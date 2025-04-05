#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

bool isOdd = true;
mutex mtx;
condition_variable cv;

void print_even(int n){
    for(int i=2;i<=n;i+=2){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[&](){
            return !isOdd;
        });
        cout << i << endl;

        isOdd = true;
        cv.notify_one();
    }
}

void print_odd(int n){
    for(int i=1;i<=n;i+=2){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock,[&](){
            return isOdd;
        });
        cout << i << endl;

        isOdd = false;
        cv.notify_one();
    }
}


int main(){

    int n = 10;

    thread t1(print_odd,n);
    thread t2(print_even,n);

    t1.join();
    t2.join();
    return 0;
}