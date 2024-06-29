#include <iostream>

using namespace std;

int main() {
    cout << "Hello World!" << endl;

    // Reference must be declared and defined at the same time
    int a = 10;
    int& b = a; // int& b; is a compiler error
    int c = 20;
    b = c; // This is okay because b is just the alias of a so all of them are now 20 
    // &b = c; // Compiler error, a ref cannot be rebinded to another variable
    // int&& d = b; // Compiler error, because ref is not an object in memory, ref to ref is not possible (be aware that this is double pointer notation but actually && is rvalue ref)

    // Reference cannot be attached to value or expression
    int d = 30; // d is called lvalue and 30 is rvalue
    // int& e = 30; // Compiler error, cannot bind to rvalue for lvalue ref
    int& e = d; // e is called lvalue reference to int and it binds the lvalue d
    int&& f = 40; // 40 is rvalue so f is called rvalue ref where it binds a temp object

    return 0;
}