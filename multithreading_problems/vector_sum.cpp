#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <numeric>

using namespace std;

int single_thread_sum(vector<int> &v){
    return accumulate(v.begin(),v.end(),0);
}

void partial_sum_1(vector<int> &data,int start,int end,int &res){
    res = accumulate(data.begin()+start,data.begin()+end,0);
}

int mulithreading_sum(vector<int> &v){
    int num_threads = thread::hardware_concurrency();
    vector<int> res(num_threads,0);
    vector<thread> threads;

    int chunk_size = v.size() / num_threads;

    for(int i=0;i<num_threads;i++){
        int start = i * chunk_size;
        int end = (i == num_threads - 1) ? v.size() :(i+1) * chunk_size;
        threads.emplace_back(partial_sum_1,ref(v),start,end,ref(res[i]));
    }

    for(int i=0;i<num_threads;i++){
        threads[i].join();
    }

    return accumulate(res.begin(),res.end(),0);
}

int main(){

    const int TOTAL = 1000000;
    vector<int> vec(TOTAL,1);

    // sum of all elements inside vector
    auto start = std::chrono::high_resolution_clock::now();

    int res1 = single_thread_sum(vec);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << "res1" << res1 << endl;
    std::cout << "Time taken by function: " << duration.count() << " seconds" << std::endl;

    // multithreading
    start = std::chrono::high_resolution_clock::now();

    int res2 = mulithreading_sum(vec);

    cout << "res2" << res2 << endl;
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Time taken by function: " << duration.count() << " seconds" << std::endl;

    // multithreading much time because
    // - it creates time to create thread
    // - it takes time in context switching

    return 0;
}