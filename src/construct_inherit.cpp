#include <iostream>

using namespace std;

class Base {
public:
    Base() { 
        cout << "Base()" << endl;
    }

    Base(int i) : Base() // delegate constructor
         //, nMember(i), cMember('a')   // can't mix member initialization with constructor delegation
    {
         nMember = i;
         cMember = 'a';
         cout << "Base(" << i << ")" << endl; 
    }

    void func(double d) { cout << "Base::func(" << d << ")" << endl; }

protected:
    int  nMember = 1; // declare and init
    char cMember {'c'};
};

class Derived: Base {
public:
    using Base::Base;  // inherit construct from Base classs
    using Base::func;  // so that func(double) can be used on Derived

    void func(void) { cout << "Derived::func(void)" << endl; }

    int getMyData() { cout << "Derived::nMyData = " << nMyData << endl; }
    int getData() { cout << "Derived::nMember = " << nMember << ", cMember = " << cMember << endl; }

private:
    int nMyData = 2;
};

int main(){
    Derived d(100);
    d.func(1.1);
    d.getMyData();
    d.getData();
}
