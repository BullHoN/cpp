#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <shared_mutex>

using namespace std;

// synchonization
// mutex, atomic, semaphore, barriers, latch, condition variables

// mutex - we may forget to unlock it
// lock_guard<mutex> 
// types of mutex - shared_mutex, recursive_mutex, timed_mutex

mutex mt; // simple usecases lock_guard
// recursive_mutex mrt; // lock the same mutex again and again recursion
// timed_mutex tmt; // we can define the time duration
// shared_mutex smt; // shared_lock can read while only lock will have write access
// unique_lock lck;// unique lock   
// to avoid deadlock 
// use threads in the same order
// use lock(mtx1,mtx2) - will take both the lock together


void printSafe(const string &message){
    unique_lock<mutex> lg(mt);
    cout << message << endl;
}

void threadFunction(int id){
    for(int i=0;i<5;i++){
        printSafe("Thread " + to_string(id) + " is running");
    }
}

int main(){
   
    thread t1(threadFunction,1);
    thread t2(threadFunction,2);

    t1.join();
    t2.join();


    return 0;
}
