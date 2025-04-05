#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>

using namespace std;

shared_mutex mtx;

void writer(){
    unique_lock<shared_mutex> lock;
    cout << "writer" << endl;
}

void reader(){
    shared_lock<shared_mutex> lock;
    cout << "reader" << endl;
}

int main(){

    return 0;
}