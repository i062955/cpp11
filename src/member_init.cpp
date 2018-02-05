#include <iostream>

using namespace std;

struct Mem {
    Mem() {
        cout << "Mem(), num = " << num << endl;
    }
    Mem(int i) : num(i) {
        cout << "Meme(int), num = " << num << endl;
    }
    int num = 2;
};

class Group
{
public:
    Group() {
        cout << "Group(), val = " << val << endl;
    }

    Group(int i): val('G'), a(i) {
        cout << "Group(int), val = " << val << endl;
    }

    void NumOfA() {
        cout << "num of A: " << a.num << endl;
    }
    void NumOfB() {
        cout << "num of B: " << b.num << endl;
    }

private:
    char val{'g'};
    Mem  a;
    Mem  b{19};
};

int main(){
    Mem member;
    Group group;

    group.NumOfA();
    group.NumOfB();

    Group group2(7);
    group2.NumOfA();
    group2.NumOfB();
}
