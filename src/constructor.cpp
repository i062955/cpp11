#include <iostream>

using namespace std;

class classA {
public:
    classA() : pData(new int(3)) {
        cout << "default construct: " << ++n_cstr << endl;
    }

    classA(const classA& h): pData(new int(*h.pData)) {
        cout << "copy construct: " << ++n_cptr << endl;
    }

    classA (classA&& rhs): pData(rhs.pData) {
        rhs.pData = nullptr;
        cout << "move construct: " << ++n_mvtr << endl;
    }

    ~classA() {
        delete pData;
        cout << "destruct: " << ++n_dstr << endl;
    }

    int *pData;
    static int n_cstr;
    static int n_dstr;
    static int n_cptr;
    static int n_mvtr;
};

int classA::n_cstr = 0;
int classA::n_dstr = 0;
int classA::n_cptr = 0;
int classA::n_mvtr = 0;

classA getTemp() {
    classA a;
    cout << "resource from " << __func__ << ": " << hex << a.pData << endl;
    return a;
}

int main() {
    classA temp (getTemp());
    cout << "resource from " << __func__ << ": " << hex << temp.pData << endl;
}
