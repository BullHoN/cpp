#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


template<typename T1>
T1 Add(T1 a,T1 b){ // trailing return type
    return a + b;
}

// template Specialization
template <>
const char* Add(const char* a,const char* b) {
    string result = string(a) + string(b);
    return strdup(result.c_str()); 
}

template<typename T>
typename T::value_type sum(T arr){
    typename T::value_type res{};
    for(auto it : arr){
        res += it;
    }
    return res;
}

struct Game {
    int level;
    string difficult;

    Game(int l,string diff) : level(l), difficult(diff) {}

    friend ostream& operator << (ostream& os,const Game &obj){
        os << obj.level << " " << obj.difficult << endl;
        return os;
    }
};

template<typename T1,typename T2>
class Pair {
private:
   T1 first;
   T2 second;

public:
    Pair(T1 a, T2 b) : first(a), second(b){}

    void print(){
        cout << "first-> " << first << " ,second-> " << second << "\n";
    }

};

int main(){
    cout << Add(1,20) << endl;
    // cout << Add("Hello"," World") << endl;

    cout << Add("Hello","World") << endl;
    vector<int> arr = {1,2,3,4};
    list<int> arr2 = {3,4,5,6};
    vector<string> arr3 = {"op","op"};

    cout << sum<vector<int>>(arr) << "\n";
    cout << sum<list<int>>(arr2) << "\n";
    cout << sum(arr3) << "\n";

    Pair<string,int> p("op",2);
    p.print();

    Pair<int,Game> p2(2,Game(2,"easy"));
    p2.print();

}