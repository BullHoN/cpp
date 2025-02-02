#include <bits/stdc++.h>
#define endl "\n";
using namespace std;

template<typename T>
class A {
public:
    T data;
    A(T d) : data(d) {}

    void func(){
        cout << "Data: " << data << endl;
    }
};

template<>
class A<int> { // Explicit Specialisation
public:
    int data;
    A(int d) : data(d) {}

    void func(){
        cout << "Data from specific: " << data << endl;
    } 
};

// template<typename T1,typename T2>
// class Pair {
//     T1 num1;
//     T2 num2;
// };

// template<typename T> // Partial Specialisation
// class Pair {
//     T num1;
//     T num2;
// };

template<typename T>
class Array {
    vector<T> arr;
public:
    void push(T a){
        arr.push_back(a);
    }

    void print(){
        for(T con : arr){
            cout << con << " ";
        }
        cout << endl;
    }
};

template<>
class Array<char> {
    string arr;
public:
    void push(char a){
        arr.push_back(a);
    }

    void print(){
        for(char ch : arr){
            cout << ch << " ";
        }
        cout << endl;
    }
};

template<int N>
class Square{
public:
    static const int value = N * N;
};

// nested template params
// sort(begin_iterator,end_itertor,sort_policy)
// vector<int>::iterator

// Define a default comparator template
template <typename T>
struct DefaultComparator {
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

template <typename Iterator, template<typename T> typename Comparator>
void Sort(Iterator begin, 
            Iterator end, 
            Comparator<typename Iterator::value_type> comp) {
    sort(begin, end, comp);
}

//variadc templates - variable number of templates

// Base case for recursion
template<typename T>
auto Sum_var(T a) {
    return a;
}


template<typename  T1,typename... Args>
auto Sum_var(T1 a,Args... args){
    return a + Sum_var(args...);
}


int main(){

    A<int> a(20);
    a.func();

    A<string> b("hello");
    b.func();

    Array<int> arr1;
    arr1.push(2);
    arr1.push(3);

    arr1.print();

    Array<char> arr2;
    arr2.push('a');
    arr2.push('b');

    arr2.print();

    // type deduction
    vector<int> v = {1,2,3,4};
    int res = accumulate(v.begin(),v.end(),0);
    cout << res << endl;

    // non type template parameters
    Square<5> sq;
    cout << sq.value << endl; // calculated during compile time

    Sort(v.begin(),v.end(),greater<int>());

    cout << Sum_var(1,2,3,4,5) << "\n";

    return 0;
}