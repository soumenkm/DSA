#include <iostream>

using namespace std;

int fun() {
    return 3;
}

int main() {
    cout << "Hello World!" << endl;

    // Reference must be declared and defined at the same time
    // int a = 10;
    // int& b = a; // int& b; is a compiler error
    // int c = 20;
    // b = c; // This is okay because b is just the alias of a so all of them are now 20 
    // // &b = c; // Compiler error, a ref cannot be rebinded to another variable
    // // int&& d = b; // Compiler error, because ref is not an object in memory, ref to ref is not possible (be aware that this is double pointer notation but actually && is rvalue ref)

    // // Reference cannot be attached to value or expression
    // int d = 30; // d is called lvalue and 30 is rvalue
    // // int& e = 30; // Compiler error, cannot bind to rvalue for lvalue ref
    // int& e = d; // e is called lvalue reference to int and it binds the lvalue d
    // int&& f = 40; // 40 is rvalue so f is called rvalue ref where it binds a temp object

    // Ptr to ref is nor possible
    // This gets the address of binding obj that ref refers to, 
    // so this is not ptr to ref as ref is not object in memory, it's not possible
     
    int a = 42;
    int& ref = a;
    int* ptr = &ref; // gets base obj address

    // Ref to ptr is possible
    int* & ref2 = ptr; // ref2 is just alias of ptr (read in clockwise spiral rule)
    // ref2 is a reference to pointer to int (right to left, clockwise spiral)

    // C++ is strict in type checking for pointer
    int a1 = 20;
    int* ptr3 = &a1; // ptr3 is a pointer to int so ptr3 points to 4B memory block and it increments to 4B memory
    // char* ptr4 = &a1; // Okay in C but compiler error in C++ because ptr4 is a pointer to char so it expects to point 1B in memory but it got base address of 4B memory block

    // nullptr
    int* ptr4 = nullptr; // nullptr can be assigned to any type of pointer
    int* ptr5 = 0; // Automatically becomes nullptr but a variable with value 0 cannot be assigned for nullptr

    // Pointer equality
    int x = 20;
    int y = 30;
    int* p = &x;
    int* q = &y;

    // p == q; // False because the content of p and q are not same
    // p++;
    // q++;
    // p == q; // Again false because the content of p and q are not same

    // Void* pointer
    void* ptr6 = &x; // It can be any object and since it doesn't know the block size that it is pointing to, we can't dereference the void pointer

    // const variable
    const double pi = 3.14; // the value of the variable pi cannot be changed anymore
    // pi = 4.5; // compiler error
    const int pp = fun(); // Okay since it is runtime const
    // const int pq; // Compiler error, const cannot be uninitialized
    // In const object, we can perform those operations which won't change the value of const object
    int i = 42;
    const int j = i; // Okay since the value of i is copied in j
    int k = j; // Okay since the value of j is copied to k but during copy operation, it doesn't change the value of const object j itself so it is allowed

    // ref to const (not same as const ref)
    // ref to const object doesn't tell anything about constness of the binding object 
    // the binding object can be const or can be non-const but the ref to that object is 
    // ref to const which means the ref gets only the read access of the object. The ref to
    // const cannot write the value of obj regardless of constness of the obj but the obj itself
    // can be written outside without the help of ref to const

    const int var1 = 42; // const object
    int var2 = 32; // non const object

    const int& rc1 = var1; // rc1 is ref to const object (it thinks that it is ref to const)
    const int& rc2 = var2; // rc2 is also ref to const object (it thinks!)
    // rc1 = 56; // Compiler error since rc1 is ref to const (it thinks!)
    // rc2 = 78; // Compiler error since rc2 is ref to const (it thinks!)
    // int& rc3 = var1; // Compiler error as const obj cannot binded to ref to non const 

    // double aa = 20.5;
    // int& rr = aa; // Compiler error
    // The compiler creates a temp object which is const while making implicit type conversion
    // double aa = 20.5; --> const int temp = 20;
    // int& rr = temp;
    // Then the compiler binds the ref rr to the temp object but since the temp obj is const so
    // it cannot be binded to ref to non const as we won't be able to change the value but the 
    // programmer thinks it can change the value bacause the parent obj is non const so it's a mess!


    // Type mismatch is allowed only in 1 case for ref assignment
    const double bb = 30.4;
    // int& rr2 = bb; // Of course not possible because the ref rr2 is ref to non const which cannot bind const object
    // this is not allowed as the ref has write access but the object is not writable
    
    double cc = 32.9;
    const int& rr2 = cc; // Fine because the temp is const and the ref is also ref to const so no problem at all! and implicity the type is converted
    // cout << cc << endl << rr2; // 32.9 and 32 (be careful)

    const double dd = 43.5;
    const int& rr3 = dd; // Also fine as it is even const already

    // const ref (this concept doesn't exist)
    // internally the ref is implemented by the ptr. actually all ref are const ref by design
    // it means, once the obj is binded to a ref, it cannot be rebinded so you cannot change the 
    // ref so in that sense, all ref are const ref

    // int w = 20;
    // int* const wp = &w; // You can think that the pointer is const pointer meaning the content of wp cannot be changes
    // wp++; // Compiler error
    // The compiler will always give *wp for you so wp can be considered as ref and it is const ref by design

    // pointer to const (not same as const pointer) (called low level const)
    // this means the ptr gets only read access. It doesn't tell anything about the obj that
    // the ptr is pointing to. The obj can be const or can be non-const
    int e = 30;
    const int* pe = &e; // pe is pointer to int const or const int (it thinks!)
    // *pe = 89; // Compiler error even though the obj e is non-const
    // the rules for ptr are same for type checking with const for ref 

    // const pointer (called high level const)
    // this means the pointer itself is const meaning its content cannot be changed
    int rt = 30;
    int* const prt = &rt; // prt is const pointer to int
    // prt++; // compiler error since prt is const pointer
    // const pointer and pointer to const are independent and can be any combination

    int pr = 54;
    int* ptrr1 = &pr; // pointer to int (read and write access if possible) and can be repointed
    int* const ptrr2 = &pr; // const pointer to int (has read and write access but cannot be repointed)
    const int* ptrr3 = &pr; // pointer to int const (has read access, no write access but can be repointed)
    const int* const ptrr4 = &pr; // pointer to const int const (has read access, no write access and cannot be repointed)

    // Assigning to non const to const object is not recursive
    int* arr; // arr is pointer to int (can be const or can be non const object which we don't care)
    const int* arr2 = arr; // meaning arr2 is a pointer to const int which is not writable so it doesn't 
    // matter whether arr has write access or not for that int. It simply copies the content of arr and puts in arr2

    const int qa = 390;
    // int* qap = &qa; // Error as ptr gets write access but the object is not writable 
    // so from const int* to int* conversion is not possible. You must use const_cast to remove the const
    // for arr2 where from int* to const int* is auto converted and during this only 1 level deep
    // low level const can be converted

    char c = 'x';
    char* p1 = &c;
    // const char** p2 = &p1; // Runtime error
    // p2 is pointing to p1 and const means it thinks that p1 is a const obj but the const is 
    // not applied in 2nd level meaning it is not thinking that c is a const but c can be const also
    // suppose c is const and then through p2, you have write access which is not allowed so it's error
    const char * const * p2 = &p1; // Okay, now 2 level const is applied
    // p2 is a pointer to const pointer to const char (so from char** to const char ** is not possible)
    // the number of * must be same as number of const if we assign a non const object to a pointer to const object
    
    int z = 10;
    const int* zp = &z; // &z has type int* (non const obj) -> zp has type const int* (pointer to const obj)
    // the number of * and const should match in the LHS of the expression

    // const when using in user defined objects in class
    // We pass the object by its pointer and also a low level const to the pointer that means
    // ptr thinks that it is a pointer to const foo (it thinks it doesn't have write access to all its member variables)
    // actually compiler puts sort of a top level const over all the member variables of the obj so it
    // means the member variable of the obj that pointer points to cannot be changed using the pointer
    // but the object that the member variable points can be changed because that obj is other one
    // const is not transitive. putting const in ptr doesn't automatically put constness to all 
    // the other member variables recursively at the bottom levels.


    return 0;
}

class foo {
    public:
        int m_data{11};
        foo* m_next{nullptr};
};

void change(const foo* ptr) {
    // ptr -> m_data = 21; // Compiler error
    ptr -> m_next -> m_data = 21; // Okay because the next obj is not pointer by ptr
}