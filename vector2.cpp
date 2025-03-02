#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Vector {
private:
    T* data;

public:
    int _capacity;
    int _size;

    Vector() : data(nullptr), _capacity(0), _size(0) {}

    Vector(int initsize) : data(new T[initsize]), _capacity(initsize), _size(0) {
        
    }

    Vector(std::initializer_list<T> lst) : Vector(lst.size()) {
        for(auto &itr : lst) push_back(itr);
    }

    ~Vector(){
        clear();
    }

    void clear(){
        delete[] data;
    }

    int size() const{
        return this->_size;
    }

    int capacity() const{
        return this->capacity;
    }

    bool empty(){
        return _size == 0;
    }

    void push_back(T elem){
        if(_capacity <= _size){
            reserve(_capacity == 0 ? 1 : _capacity * 2);
        }
        data[_size++] = elem;
    }

    T& operator [] (int idx){
        return data[idx];
    }

    void reserve(int newCapacity){
        if(newCapacity > _capacity){
            T *temp = new T[newCapacity];
            for(int i=0;i<_size;i++) temp[i] = std::move(data[i]);
            delete[] data;
            data = temp;
            _capacity = newCapacity;
        }
    }

    void pop_back(){
        if(_size == 0) return;
        ~data[_size];
        data[--_size] = T();
    }

    Vector(const Vector &other) {
        _capacity = other._capacity;
        _size = other._size;
        data = new T[_capacity];
        for(int i=0;i<other._size;i++){
            data[i] = other.data[i];
        }
    }

    Vector& operator = (const Vector &other){
        if(this != &other){
            _capacity = other._capacity;
            _size = other._size;
            

            T *temp = new T[_capacity];
            for(int i=0;i<_size;i++){
                temp[i] = other.data[i];
            }

            delete[] data;
            data = temp;
        }

        return *this;
    }

    Vector(Vector&& other) : _capacity(other._capacity), _size(other._size), data(other.data){
        other.data = nullptr;
        other._capacity = 0;
        other._size = 0;
    }

    Vector& operator = (Vector&& other){
        if(this != other){

            delete[] data;

            _capacity = other._capacity;
            _size = other._size;
            data = other.data;
            
            other.data = nullptr;
            other._capacity = 0;
            other._size = 0;
        }

        return *this;
    }

    template<typename... Args>
    void emplace_back(Args... args){
        // template meta programming
    }

};

template <typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << '\n';  // Fold expression
}

class Person {
public: 
    string name;
    int age;

    Person(string n,int a) : name(n), age(a) {}
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

    // vector<Person> vcustom;
    // vcustom.emplace_back("vaibhav",1);


    // Vector<int> v1(10);
    // cout << v1.size() << " " << v1.capacity() << endl;

    // Vector<int> v;
    // cout << v.size() << " " << v.capacity() << endl;
    // Vector<int> v5 = {1,2,3,4,5};

    // for(int i=1;i<=100;i++){
    //     v.push_back(i);
    // }

    // cout << v.size() << endl;
    // v.pop_back();
    // cout << v.size() << endl;

    // cout << v[11] << endl;

    // Vector<int> v2 = v;
    // cout << "New Vector " << v2.size() << endl;

    // Vector<int> v3;
    // v3 = v2;

    // cout << "New Vector " << v3.size() << endl;

    // Vector<int> v4 = move(v2);
    // cout << v4.size() << endl;


    // print(1,2,3,4,5,"hello world");

    Vector<int> pops = {1,2,3,4};
    pops.pop_back();

    cout << pops[2] << endl;

}