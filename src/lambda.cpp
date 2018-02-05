#include <iostream>

using namespace std;

class Functor {
public:
    Functor(float rate): _freeRate(rate){}

    float operator() (float price){
        return price * (1 - _freeRate / 100);
    }

private:
    float _freeRate;
};

void tryLambda2(){
    float tax_rate = 5.5;
    Functor functor(tax_rate);

    auto lambda = [tax_rate](float price) -> float { 
        return price * (1 - tax_rate / 100);
    };

    float method1 = functor(3699);
    float method2 = lambda(3699);

    cout << "functor() = " << method1 << endl;
    cout << "lambda()  = " << method2 << endl;
}

void tryLambda1(){
    int a = 1;
    int b = 2;

    []{}; // an empty lambda

    // capture all parent scope vars by value, no parameter, auto decided return type
    [=] { return a+b; };

    // capture all parent scope vars by reference, parameter int c
    auto fun1 = [&](int c) { b = a+c; };
    fun1(10);
    cout << "after fun1, b = " << b << endl;

    // capture b by reference, all others by value
    auto fun2 = [=,&b](int c) -> int { return b+= a+c; };
    cout << "fun2(10) returns: "  << fun2(10) << endl;
    cout << "after fun2, b = " << b << endl;

    // anonymous lambda
    int d = [=](int c) { return a + b + c; } (10);
    cout << "a + b + c = " << d << endl;
}

void tryLambda3(){
    int i = 10;
    auto byValue = [=] { return i + 1; };
    auto byRefer = [&] { return i + 1; };
    cout << "i = " << i << endl;
    cout << "by value lamdba(i+1): " << byValue() << endl;
    cout << "by reference lambda(i+1): " << byRefer() << endl;

    i++;
    cout << "i = " << i << endl;
    cout << "by value lamdba(i+1): " << byValue() << endl;
    cout << "by reference lambda(i+1): " << byRefer() << endl;
}

int main() {
    tryLambda1();
    tryLambda2();
    tryLambda3();
}
