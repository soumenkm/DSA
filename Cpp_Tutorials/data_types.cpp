#include <iostream>
#include <string>

using namespace std;

extern int g; // The declaration of the varibale g

int main() {
    cout << "Hello World!" << endl; // cout is an object of ostream class in iostream header

    // Initialization types
    int a = 42; // First creates a tmp object, stores 42 and then copies the data to a and allows type conversion
    int b = {42}; // int b{42}; Recommended as it disallows type conversion
    int c = (42); // int c(42); allows type conversion and no tmp object creation
    // int c; // Not recommended at all as it is garbage initialization

    // Declaration vs Definition
    // Variables can be declared many times but they acan be defined only once.
    // g is declared here to hint that g is defined somewhere else. If 10 files want to use the 
    // variable g then it will be declared 10 times but in one of the file, it will be defined only once
    int i = {20}; // Means the definition also happens with = operator(not assignment, it is initialisation) which creates memory
    i = 30; // This is assignment that means the memory is overwritten

    // Scopes
    // Functions always have global scope as they are defined in top level of file
    // Variables without static in top level has global scope
    // Varibales with static in top level has file scope
    // Variables without static inside {} has {} scope and it will be in memory for lifetime
    // Varibales with static inside {} has no effect on scope but it will be in memory for lifetime

    // Namespace
    // We can have different files which has multiple classes but we can cluster the functions 
    // and classes of all these files and put it in a namespace. std is a namespace where the 
    // classes adn function names are stored for many libraries such as iostream, cmath, limits, string etc...
    // To access any name from namespace we use namespace_name::name. A namespace is defined by 
    // namespace name_space {...}

    // auto has different meaning in C++
    // auto is used to infer the types in compile time
    auto str = "hello"; // const char*
    auto aaa = 34.6; // double

    // decltype is used to determine the type in compiler time
    int pq = 45;
    decltype(pq) cy = 90; // means int cq = 90

    // type alias
    // typedef double df; // now double will be referred to df
    // using f = float; // now float will be referred to f
    constexpr int ap = 40; // constexpr will put top level const in object

    // string
    string s1 = "hello"; // "hello" is of type const char[6] because it ends with '\0'
    // s1 is a copy of string literal "hello"
    string s2("hello"); // this doesn't end with '\0'
    string s3(10, 'c'); // this is cccccccccc without '\0'

    // get input string (as a line)
    string line;
    string word;
    // getline(cin, line); // read one line at a time '\n' is discarded and stops when it sees '\n'
    // cin >> word; // this means only words separated by space will be taken as input and when it sees space then it stops

    // basic methods of string object
    string str1("hello");
    bool isEmpty = str1.empty(); // checks if it is empty or not
    auto len = str1.size(); // it returns size_t which is unsigned int so be careful when it is used with int in expression

    // unsigned vs signed
    int cv = -1; // 11111111 11111111 11111111 11111111
    unsigned int cb = -1; // 11111111 11111111 11111111 11111111
    cout << cv + cb << endl; // int is converted to unsigned int so %u of th ebit pattern of -1 is HUGE
    
    // concatenation of string
    string ss1("hello");
    string ss2("world");
    string ss3 = ss1 + "world"; // auto converted to string if any one of operand is string
    // string ss4 = "hello" + "world"; // error as + is not defined for const char[N]












    return 0;
}