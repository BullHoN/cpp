#include <iostream>
#include <string.h>
using namespace std;

class String {
private:
    char *res;
    unsigned int len;
public:
    String() : res(nullptr), len(0) {

    }

    String(const char *ch){
        len = strlen(ch);
        res = new char[len+1];
        strcpy(res,ch);
    }

    String(const String &other){
        len = other.len;
        res = new char[len+1];
        strcpy(res,other.res); 
    }

    String(String &&other){
        len = other.len;
        res = other.res;

        other.res = nullptr;
        other.len = 0;
    }

    String& operator = (const String &other){
        if(this != &other){
            char *temp = new char[other.len+1];
            delete[] res;
            res = temp;
            len = other.len;
            strcpy(res,other.res);
        }

        return *this;
    }

    String& operator = (String &&other){
        if(this != &other){
            len = other.len;
            res = other.res;
    
            other.res = nullptr;
            other.len = 0;
        }

        return *this;
    }

    unsigned int length(){
        return len;
    }

    friend ostream& operator << (ostream &out,const String &str);
    friend istream& operator >> (istream &in,const String &str);

    ~String(){
        if(res) {
            delete[] res;
            res = nullptr;
            len = 0;
        }
    }

};

ostream& operator << (ostream &out,const String &str){
    out << str.res;
    return out;
}

istream& operator >> (istream &in,const String &str){
    in >> str.res;
    return in;
}


int main(){

    String str1; // default ctor
    String str2 = "hello"; // parameterised ctor
    String str3 = str1; // copy ctor
    str3 = str2; // copy assignment operator

    int len = str2.length();

    cout << str2 << endl; // overloading <<
    cin >> str1; // overloading >>

    String str6 = std::move(str2);

    return 0;
}