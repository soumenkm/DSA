#include <iostream>
using namespace std;

int func() {
    static int i = {0};
    i = i + 2;
    return i;
}

int add(int num1, int num2) {
    // num1 and num2 are called parameters. They are local to add and they will be 
    // initialized by the arguments that are passed when the function is called. If
    // the param is ref then it is bound to its argument, otherwise the arg value is copied 
    // to the param. When param is ref then the arg is passed by ref and func is called by ref
    // otherwise it is passed by value and called by value. When we copy a pointer, the value
    // of pointer is copied, after the copy two pointers are distinct.
    int res = num1 + num2;
    return res;
}

int calcLen(const string* str) {
    // string can be large so it is inefficient to pass the entire string by value so we 
    // pass the pointer to the string which is only 8B and using the pointer, we will 
    // manipulate the string. Since we don't want to give the write access to str so we also
    // wrap it with a low level const so str ptr thinks that it is const
    // We could have passes const string& str also which is ref to const so by default, str cannot
    // be rebinded to any other variable (all ref are const ref by design). On constrary, for pointers
    // we may have to write const string* const str to enfore const pointer
}


int main() {
    // scope and lifetime
    // a functions name has a scope which defines where it is accessible and lifetime
    // defines how long it is accessible. static int i means i will be created under func's scope
    // and it is stored in static data region which is not destroyed unless program terminates. Each
    // time func is called, it can access this varible beause it is func's name scope. Even if func
    // is called recuresively, still it will be able to access because it is func's name scope

    // for (int i = 0; i < 10; i++) {
    //     cout << func() << " " << i << endl;
    // }

    // array handling
    // begin(arr), end(arr) returns the negin and end pointer of an array
    int arr[] = {1, 2, 3, 4, 5};
    int* first = begin(arr); // same as &arr[0] or arr itself but don't do &arr since it will not match the type
    int* last = end(arr);
    // int* ptr = &arr; // Error, &arr is of type int (*)[5] because it is pointer to array of 5 ints

    return 0;
}