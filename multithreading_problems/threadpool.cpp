#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <future>

using namespace std;

int print(int a){
    cout << "hello " << a << endl;
    return a + 5;
}

class Threadpool {
private:
    int m_threads;
    vector<thread> threads;
    queue<function<void()>> tasks;
    mutex mtx;
    condition_variable cv;
    bool stop; 
public:

    explicit Threadpool(int numThreads) : m_threads(numThreads), stop(false) {
        for(int i=0;i<m_threads;i++){
            threads.emplace_back([this](){
                function<void()> task;
                while(1){
                    unique_lock<mutex> lock(mtx);
                    cv.wait(lock, [this]() {
                        return !tasks.empty()  || stop;
                    });

                    if(stop) {
                        return;
                    }

                    task = move(tasks.front());
                    tasks.pop();

                    lock.unlock();
                    task();
                }
            });
        }
    }

    ~Threadpool(){
        unique_lock<mutex> lock(mtx);
        stop = false;
        lock.unlock();
        cv.notify_all();

        for(auto &th : threads){
            th.join();
        }
    }

    template<class F,class... Args>
    auto executeTask(F&& f, Args&&... args) -> future<decltype(f(args...))>{
        
        using return_type = decltype(f(args...));

        auto task = make_shared<packaged_task<return_type()>>(bind(forward<F>(f),forward<Args>(args)...));
        
        future<return_type> res = task->get_future();
        
        unique_lock<mutex> lock(mtx);
        tasks.emplace([task]() -> void{
            (*task)();
        });
        lock.unlock();

        cv.notify_one();

        return res;
    }
};

int main(){

    Threadpool pool(8);
    future<int> res = pool.executeTask(print,1);
    cout << res.get() << endl;

    return 0;
}