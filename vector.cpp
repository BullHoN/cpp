#include <bits/stdc++.h>
#define endl "\n";
using namespace std;

template<typename T>
class Vector {
private:
    int _capacity;
    int _size;
    T *arr;
public:
    // 
    Vector(){
        reserve(1);
    }

    // create vector of initial fixed size
    Vector(int capacity){
        reserve(capacity);
    }

    // copy constructor
    Vector(const Vector<T> &v2){
        int n = v2.size();
        reserve(n);
        for(int i=0;i<n;i++) arr[i] = v2[i];
        _size = n;
    }


    T& operator [](int idx) const{
        if(idx >= _size){
            throw runtime_error("OutOfBound");
        }

        return arr[idx];
    }

    void push_back(T obj){
        if(_size == _capacity){
            // increase the current capacity
            _capacity = 2 * _capacity;
            T *newArr = new T[_capacity];

            // copy the objects
            for(int i=0;i<_size;i++) newArr[i] = arr[i];
            
            // delete previous array
            delete[] arr;

            arr = newArr;
        }
        arr[_size] = obj;
        _size++;
    }

    void pop_back(){
        if(_size == 0) return;
        arr[_size] = T();
        _size--;
    }

    void reserve(int capacity){
        _capacity = capacity;
        this->_size = 0;
        arr = new T[_capacity];
    }

    bool empty(){
        return _size == 0;
    }

    int size() const {
        return this->_size;
    }

    int capacity(){
        return this->_capacity;
    }

    ~Vector(){
        clear();
    }

    void clear(){
        cout << "clear vector" << endl;
        delete[] arr;
    }

};

int main(){

    // requirements
    // vector<int> v2;
    // v2.pop_back();
    
    // v.push_back(1); 
    // v.pop_back();
    // cout << v[0] << "\n";
    // v.size();
    // v.clear();
    // v.empty()

    // vector<int> v2;
    // v2 = v;

    // vector<int> v3 = {1,2,3,4};

    // Vector<int> v1(10);
    // cout << v1.size() << " " << v1.capacity() << endl;

    Vector<int> v;
    // cout << v.size() << " " << v.capacity() << endl;


    for(int i=1;i<=100;i++){
        v.push_back(i);
    }

    cout << v.size() << endl;
    v.pop_back();
    cout << v.size() << endl;

    cout << v[11] << endl;

    Vector<int> v2 = v;
    cout << "New Vector " << v2.size() << endl;

    Vector<int> v3;
    v3 = v2;

    cout << "New Vector " << v3.size() << endl;


}