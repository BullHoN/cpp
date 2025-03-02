#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

template<typename T>
class Shared_ptr{
private:
    T* m_ptr;
    int *m_count;

    void release(){
        if(m_count){
            (*m_count)--;
            if((*m_count) == 0){
                delete m_ptr;
                delete m_count;
                m_count = nullptr;
                m_ptr = nullptr;
            }
        }
    }

public:

    Shared_ptr() : m_ptr(nullptr), m_count(nullptr) {}

    Shared_ptr(T *ptr) : m_ptr(ptr), m_count(new int(1)) {}

    Shared_ptr(const Shared_ptr<T> &other) {
        m_ptr = other.m_ptr;
        m_count = other.m_count;
        (*m_count)++;
    }

    Shared_ptr(Shared_ptr<T> &&other){
        m_ptr = other.m_ptr;
        m_count = other.m_count;

        other.m_ptr = nullptr;
        other.m_count = nullptr;
    }

    Shared_ptr<T>& operator = (const Shared_ptr<T> &other){
        if(this != &other){
            release();
            m_ptr = other.m_ptr;
            m_count = other.m_count;
            (*m_count)++;
        }

        return *this;
    } 

    Shared_ptr<T>& operator = (Shared_ptr<T> &&other){
        if(this != &other){
            release();
            m_ptr = other.m_ptr;
            m_count = other.m_count;
            
            other.m_ptr = nullptr;
            other.m_count = nullptr;
        }

        return *this;
    } 


    T* get(){
        return m_ptr;
    }

    void reset(T *ptr = nullptr){
        release();
        m_ptr = ptr;
        m_count = new int(1);
    }

    T& operator * (){
        return *m_ptr;
    } 

    T* operator -> (){
        return m_ptr;
    }

    ~Shared_ptr(){
        release();
    }

};

int main(){

    cout << "Shared Pointer" << endl;

    Shared_ptr<int> ptr1;
    int *p = new int(20);

    Shared_ptr<int> ptr2(p);
    Shared_ptr<int> ptr3(new int(20));
    
    Shared_ptr<int> ptr4(ptr3);

    ptr3 = ptr2;

    ptr2.reset();

    cout << *ptr3 << endl;

    return 0;
}