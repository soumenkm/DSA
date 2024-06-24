#include <iostream>

using std::cout, std::endl, std::flush;

void fun3() {
    int a3 = 3;
    int* ptr = nullptr;
    //cout << *ptr << endl;
}

void fun2() {
    int a2 = 2;
    fun3();
}

void fun1() {
    int a1 = 1;
    fun2();
}

int main() {
    cout << "Hello World!" << endl;
    int a = 0;
    fun1();
    return 0;
}