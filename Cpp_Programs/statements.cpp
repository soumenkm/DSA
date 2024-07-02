#include <iostream>

using namespace std;

int f() {
    return 1;
}
int g() {
    return 2;
}
int h() {
    return 3;
}
int j() {
    return 4;
}

int main() {
    cout << "Hello World!" << endl;

    // Order of evaluation, precedance and associativity
    // Precedence guarentees that the result of g() and h() are multiplied
    // Associativity guarentees that the result of f() and mult are added
    // There is no guarentee on the order of calling f, g, h, j. There are 4! ways to evaluate them
    // If 4 functions change the state of one object then the behaviour is undefined otherwise
    // it doesn't matter. ||, &&, :? operators are evaluated left to right

    int a = f() + g() * h() + j(); // evaluation doesn't matter
    // cout << a << " " << ++a << endl; // undefined behaviour

    // static_cast (safe)
    int i = 86;
    int j = 20;
    double k = i / j; // k is double but the division is integer division
    double k1 = static_cast<double>(i) / j; // now it is float division
    // double* ptr = &i; // Compiler error as int* cannot be initialized to double*
    // double* ptr = static_cast<double*>(&i); // Compiler error as int* cannot be converted to double*
    void* ptr = &i; // ptr is pointing to base address of i but it is not pointing to whole memory block or the dereferencing is not allowed and jumping also not allowed
    // ptr++; // Compiler error as jumping 
    double* ptr2 = static_cast<double*>(ptr); // This is fine now but be careful with ptr2
    // dereferencing ptr2 will give unexpected result as it will dereference 8B of memory 
    // cout << i << " " << *ptr2 << endl; // 86 2.3342e-313 (completely garbage because of last 4B of garbage)
    // To change the pointer type, first convert it to void* and then cast it to desired type

    // const_cast (medium dangereous)
    int qq = 20;
    const int* pqq = &qq; // pqq gets only read access of qq, it has a low level const
    // int* pqq2 = static_cast<int*>(pqq); // Complier error, static cast cannot remove low level const
    int* pqq2 = const_cast<int*>(pqq); // pqq2 doesn't have low level const so it gets the write access of pqq
    *pqq2 = 30;
    // cout << qq << " " << *pqq2 << endl; // 30 30, pqq2 has changed the value
    // cout << &qq << " " << pqq2 << endl; // 0x16b96b42c 0x16b96b42c, *pqq and qq are same memory

    // be careful since if the underlying object is actually const then by casting away the low
    // level constness actually gives lot of power to the pointer to change the value of even const object
    const int rr = 20;
    const int* prr = &rr;
    int* prr2 = const_cast<int*>(prr); // prr2 now has write access of the const object which is undefined behaviour
    *prr2 = 30;
    // cout << rr << " " << *prr2 << endl; // 20 30, the memory is actually modified but compiler optimizes by const expression so it simply replace the value of rr as 20
    // cout << &rr << " " << prr2 << endl;// the const obj is changed by const_cast! It is really problematic

    // reinterpret_cast (most dangereous)
    // it allows to reinterpret the memory block pointed by a pointer
    int ss = 97;
    int* pss = &ss; // pss points to 4B in memory and jumps over 4B
    char* pss2 = reinterpret_cast<char*>(pss); // converts int* to char* so pss2 points to 1B in memory and jumps to 1B. 
    *pss2 = 98; // we modified the actual object value of ss! (dangereous!)
    cout << *pss2 << endl; // it prints b

    // function and C style cast
    int zz = 30;
    double xx = double(zz) / 3.0; // function type cast
    double yy = ((double) zz) / 3.0; // C style cast

    // old C style cast can be static or const or reinterpret whenever available so do not
    // use it as the name is auto converted if possible so always use named cast for more clarity
    // char* pc = (char*) pss; // this takes the form of reinterpret cast so it's not so clear and hard to spot on


    return 0;
}