#include <iostream>
#include <string>

using namespace std;

class A {
    // class means by default all attributes are private and struct means by default all attributes
    // are public but both are functionally equivalent
private:
    int a = 10;
public:
    A(int a) {
        this -> a = a;
    }
    void print() const {
        // this is a pointer to const meaning only top level const is enforced but
        // const member functions means this is const pointer to const meaning both
        // top and low level const are enforced.
        // this -> a = 40; // Compiler error since this is low level const so it doesn't have write access to object members
        // low level const on objects makes sure that it puts a top level const on all the member variables
        // of that object but indirectly it can change the member variables of other objects because
        // the const ness is not recursive. It only protects the constness of the object on which this refers to, not others
        cout << this -> a << endl;
    }
    void printA() {
        cout << this -> a << endl;
    }
};

class Book {
private:
    const string* name = {nullptr};
    const int pages = {0};
    int bookmark = {0};
public:
    Book() = default; // It will call default constructor (garbage init of members)
    // we could have also defined the default constructor by providing 0 parameters
    Book(const string* const name, const int bookmark) {
        this -> name = name;
        // this -> pages = pages; // this is an error because we are modifying the const value
        this -> bookmark = bookmark;
    }
    Book(const string* const name, const int pages, const int bookmark):
        name{name}, pages{pages}, bookmark{bookmark} {}
        // this is called list initialization which is a shortcut to initialize all the 
        // members even if they are const. Here compiler will not raise any error. We used
        // {} initialization instead of () init method for type safety
    Book(const Book& other) {
        // It is copy constructor where we have to pass by ref as if we pass by value then
        // it will again call copy constructor and infinite loop will begin. And it is const
        // becuase we don't want to modify the value of the other object
        this -> name = other.name;
        // this -> pages = other.pages; // Not possible because pages is const
        this -> bookmark = other.bookmark; 
    }
};

class Car {
    int seat = {4};
    int color = {0};
    int price = {0};

public:
    Car(const int _seat, const int _color) {
        this -> seat = _seat;
        this -> color = _color;
        cout << "Direct constructor called" << endl;
    }
    Car(const Car& other) {
        this -> seat = other.seat;
        this -> color = other.color;
        cout << "Copy constructor called" << endl;
    }
    Car() {
        this -> seat = 0;
        this -> color = 0;
        cout << "Default constructor called" << endl;
    }
    explicit Car(const int _seat, const int _color, const int _price) {
        // Class obj = 10 (this is not allowed for single parameters)
        // We have to always explicitly call the constructor to create the object
        // Class obj = {...} initialization (list initialization) is not allowed
        // The type conversion in the paramters are still allowed. Use {} to prevent this
        this -> seat = _seat;
        this -> color = _color;
        this -> price = _price;
        cout << "Explicit Direct constructor called" << endl;
    }
    explicit Car(const int _seat) {
        this -> seat = _seat;
    }
    ~Car() {
        // This isd destructor and it is called when we use delete obj
        // When are dynamically created in heap, then we need a destructor
    }

};

class Bank {
public:
    // static members are shared across all the objects of the class. They can be declared
    // in class but defined outside of class using class_name::member operator
    // If we want to define it in class then we have to make it const. Static members are 
    // accessed by :: operator. All objects of the class, shares the same static member. The 
    // change in one object will refelect in another object. They can be called without creating
    // the objects of the class. They are associated with the class as a whole. Static functions 
    // doesn't have access to non static members of the class. Since static members are not 
    // associated with any objects so they cannot be defined by calling constructors.
    static constexpr double roi = {6.8}; // it has to be constexpr
    static double stock_price; // This will be initialized outside of class (at top level of file)

public:
    static void print() {
        cout << Bank::stock_price << endl;
    }
};

class Base {
private:
    // inaccessible outside of Base class
    int a = {20};
protected:
    // accessible to only this class and its derived classes through access mode
    int b = {30};
public:
    // accessible to everywhere (may become private or protected in Derived class)
    int c = {40};
};

class Derived1: private Base {
    // private access mode means 
    // public and protected members of Base class will become private
    // private members of Base class will become inaccessible (always)
};
class Derived2: protected Base {
    // protected access mode means 
    // public and protected members of Base class will become protected
    // private members of Base class will become inaccessible (always)
};
class Derived3: public Base {
    // public access mode means 
    // public and protected members of Base class will remain unchanged 
    // meaning public will remain public and protected will remain protected
    // private members of Base class will become inaccessible (always)
};

class Complex {
    double real = {0.0};
    double imag = {0.0};

public:
    Complex() = default;
    Complex(const double _real, const double _imag):
        real{_real}, imag{_imag} {}
    Complex(const Complex& otherRef) {
        this -> real = otherRef.real;
        this -> imag = otherRef.imag;
    }
    void print() const {
        cout << this -> real << " + " << this -> imag << "i" << endl;
    }
    Complex operator+(const Complex& other) const {
        // In operator overloading, you must pass the reference to use the opeartors 
        // by actual operator symbol. If you use pointer then you must use &other in operator call
        Complex res = Complex();
        res.real = this -> real + other.real;
        res.imag = this -> imag + other.imag;
        return res;
    }
};

double Bank::stock_price = {8.4}; // this type need to be specified
int main() {
    cout << "Hello World!" << endl;
    const int a = 10;
    const int* p = &a; // fine because p is low level ptr
    const A obj = A(20); // obj is const A
    const A* ptr = &obj; // ptr is a low level pointer to const A
    // by default this is top level const pointer to A but when we call methods of obj which is 
    // const A that means this will have to be passed as low level pointer to const objct to
    // match the type compatibility otherwise compiler error will occur. That's why const objects
    // can call only the const member functions. Similarly, pointer to const object can only call
    // const member functions. The exception is constructor which should not be defined as const
    // obj.print(); // This is okay since print is const function
    // obj.printA(); // Complier error
    // ptr -> printA(); // Complier error

    const string name("mybook");
    Book book = Book(&name, 30, 5);
    Book another = Book(book);

    // Different constructors
    // Car obj1 = Car(5, 8); // Direct constructor
    // Car obj2 = {5, 8}; // Direct constructor
    // Car obj3(5, 8); // Direct constructor
    // Car obj4{5, 8}; // Direct constructor
    
    // Car obj6 = Car(obj1); // Copy constructor
    // Car obj7 = {obj1}; // Copy constructor
    // Car obj8(obj1); // Copy constructor
    // Car obj9{obj1}; // Copy constructor

    // Car obj10 = Car(5, 8, 9); // Explicit Direct constructor
    // Car obj11 = {5, 8, 9}; // It is error as the class constructor is explicit
    // Car obj12(5, 8, 9); // Explicit Direct constructor
    // Car obj13{5, 8, 9}; // Explicit Direct constructor

    // Car obj14 = 10; // This is complier error (int to Car is implicitly not converted)
    // Car obj14 = 10; // This will be no error when it is not explicit as int to Car is implicitly performed by the complier

    // Dynamic memory allocation
    int* p1 = new int{40}; // dynamically created an int
    int num = {20};
    int* arr = new int[num];
    delete[] arr; // deallocate it
    
    Book* bp = new Book(book); // obj is created in heap
    delete bp; // calls the destructor of the object

    // Operator overloading
    // functions can be overloaded by their different definition signature but opeartor
    // is overloaded using operator method
    Complex z1 = Complex(2.4, 3.5);
    Complex z2 = Complex(2.4, 3.5);
    Complex z3 = z1 + z2;
    z3.print();

    return 0;
}