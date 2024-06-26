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
    int c; // Not recommended at all as it is garbage initialization

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

    return 0;
}