#include <memory>
#include <iostream>

using namespace std;

void uniquePtr(int i) {
    unique_ptr<int> up1(new int(i));
    cout << "up1 points to: " << *up1 << endl;

    // can't copy to another one 
    // unique_ptr<int> up2 = up1;

    unique_ptr<int> up3 = move(up1);
    cout << "up1 moves to up3." << endl;
    cout << "up3 points to: " << *up3 << endl;

    // now up1 is invalid after moved to sp3
    // cout << *up1 << endl;
    up1.reset(); // but up1 is still safe to reset()

    up3.reset();
    // now up3 is invalid too after reset
    // cout << *up3 << endl;
}

void sharedPtr(int i) {
    shared_ptr<int> sp1(new int(i));
    // shared_ptr can be copied to another, reference counting actually
    shared_ptr<int> sp2 = sp1;
    // both pointer to the same content
    cout << "sp1 points to: " << *sp1 << endl;
    cout << "sp2 points to: " << *sp2 << endl;

    // after sp1 reset, sp2 is still valid.
    sp1.reset();
    cout << "sp1 reset." << endl;
    // cout << *sp1 << endl;
    cout << "sp2 still points to: " << *sp2 << endl;
}

void checkPointer (weak_ptr<int> &wp) {
    shared_ptr<int> sp = wp.lock();
    if (sp != nullptr)
        cout << "sp is valid, points to: " << *sp << endl;
    else
        cout << "sp is now invalid" << endl;
}

void weakPtr(int i) {
    shared_ptr<int> sp1(new int(i));
    shared_ptr<int> sp2 = sp1;
    weak_ptr<int> wp = sp1;

    cout << "sp1 points to: " << *sp1 << endl;
    cout << "sp2 points to: " << *sp2 << endl;
    checkPointer(wp);

    sp1.reset();
    cout << "sp1 reset, sp2 points to: " << *sp2 << endl;
    checkPointer(wp);

    sp2.reset();
    cout << "sp2 reset" << endl;
    checkPointer(wp);
}

int main(){
    cout << "------ try unique_ptr(10) ------" << endl;
    uniquePtr(10);

    cout << "------ try shared_ptr(20) ------" << endl;
    sharedPtr(20);

    cout << "------ try weak_ptr(30) ------" << endl;
    weakPtr(30);
}

