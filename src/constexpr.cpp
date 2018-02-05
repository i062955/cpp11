#include <iostream>

using namespace std;

// a function returns const int can not work in main below
//const int getConst() { return 1; }
constexpr int getConst() { return 1; }

int main(){
    int arr[getConst()] = {0};
    enum {e1 = getConst(), e2 };

    int cond = 1;
    switch (cond) {
        case getConst():
            cout << cond << endl;
            break;
        default:
            break;
    }
}
