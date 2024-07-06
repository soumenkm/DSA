#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>

using namespace std;

int main() {
    // size_type
    vector<int> v1 = {30, 50};
    vector<int>::size_type s1 = v1.size(); // mostly unsigned int so be careful in expression
    // cout << s1 << endl;
    
    // iterator and const_iterator
    vector<int> vec = {20,30,40};
    vector<int>::iterator it = vec.begin(); // it has read and write access
    vector<int>::const_iterator it2 = vec.begin(); // it has only read access. Treat it2 as pointer to const int
    *it = 40;
    // *it2 = 40; // Not allowed
    it++;

    // value_type, reference, const_reference
    vector<int> v2 = {10, 40};
    auto var = v2[0]; // var is of type vector<int>::value_type (similar to int)
    vector<int>::reference var2 = v2[0]; // var2 is similar to reference to int
    vector<int>::const_reference var3 = v2[0]; // var3 cannot be used to modify v2[0].

    // difference_type
    vector<int> arr1 = {10, 20, 30, 40};
    auto x1 = arr1.begin();
    auto x2 = arr1.end();
    vector<int>::difference_type x3 = x1 - x2; // x3 is similar to type signed int
    // cout << x3 << endl;

    // copy init
    list<string> list1 = {"book1", "book2", "book3"};
    vector<string> list2 = {"auth1", "auth2", "auth3"};
    // vector<string> list3(list1); // Error as list and vector must match
    vector<const char*> list4 = {"title1", "title2", "title3"};
    // vector<string> list5(list4); // Error as vector type string does not match with type const char*
    vector<string> list6(list2); // Okay since container type ane element type matches
    
    // range copy
    auto b = list2.cbegin(); // pointer to begin elem
    auto e = list2.cend(); // pointer to end elem
    b++;
    vector<string> list7(b, e); // Okay 
    vector<string> list8(list4.begin(), list4.end()); // Also okay as const char* to string is possible to convert

    // insert
    vector<int> pp = {10, 20, 30};
    auto pt = pp.cend();
    auto iti = pp.insert(pt, 90);
    cout << *iti << endl;

    // map
    map<string, int> amap = {{"key1", 10}, {"key2", 20}};
    auto map_it = amap.begin();
    auto ret = amap.insert({"key3", 30});

    return 0;
}