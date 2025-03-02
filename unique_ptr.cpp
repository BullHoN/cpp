#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Unique_ptr {
private:
    T* res;

public:

    Unique_ptr(T* a = nullptr): res(a) {}

    Unique_ptr(const Unique_ptr<T>& ptr) = delete;

    Unique_ptr<T>& operator = (const Unique_ptr<T>& ptr) = delete;

    Unique_ptr(Unique_ptr<T>&& ptr){
        res = ptr.res;
        ptr.res = nullptr;
    }

    Unique_ptr<T>& operator = (const Unique_ptr<T>&& ptr){
        if(this != &ptr){
            if(res){
                delete res;
            }
            res = ptr.res;
            ptr.res = nullptr;
        }

        return *this;
    }

    T* operator -> () {
        return res;
    }

    T operator * () {
        return *res;
    }

    T* get(){
        return res;
    }

    void reset(T* newres = nullptr){
        if(res){
            delete res;
        }
        res = newres;
    }


    ~Unique_ptr(){
        if(res){
            delete res;
            res = nullptr;
        }
    }

};

int main(){

    Unique_ptr<int> ptr1(new int(2));
    Unique_ptr<int> ptr2(ptr1); // compilation error
    Unique_ptr<int> ptr3 = ptr1; // compilation error
    Unique_ptr<int> ptr4(new int(500));
    ptr4 = ptr3; // compilation error
    Unique_ptr<int> ptr5 = move(ptr1);

    ptr1->func();
    cout << *ptr1;
    ptr1.get();
    ptr1.reset(new int(30));

    return 0;
}