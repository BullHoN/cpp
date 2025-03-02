#include <iostream>
#include <memory>

using namespace std;

class Parent;

class Child {
public:
    weak_ptr<Parent> parent;
    Child() { cout << "Child Created\n"; }
    ~Child() { cout << "Child Destroyed\n"; }
};

class Parent {
public:
    shared_ptr<Child> child;
    Parent() { cout << "Parent Created\n"; }
    ~Parent() { cout << "Parent Destroyed\n"; }
};

int main(){

    shared_ptr<Parent> parent = make_shared<Parent>();
    shared_ptr<Child> child = make_shared<Child>();

    parent->child = child;
    child->parent = parent;

    return 0;
}