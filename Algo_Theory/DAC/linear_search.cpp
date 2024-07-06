#include <iostream>
using namespace std;

bool linearSearchArray(const double* const array, const int num_elem, const double elem) {
    if (num_elem <= 0) {
        throw runtime_error("Num of elem must be at least 1");
    } else if (num_elem == 1) {
        if (array[0] == elem) {
            return true;
        } else {
            return false;
        }
    } else {
        bool left_res = linearSearchArray(array, num_elem/2, elem);
        bool right_res = linearSearchArray(array + num_elem/2, num_elem - num_elem/2, elem);
        return left_res || right_res;     
    }
}

int linearIndexArray(const double* const array, const int num_elem, const double elem) {
    if (num_elem <= 0) {
        throw runtime_error("Num of elem must be at least 1");
    } else if (num_elem == 1) {
        return (array[0] == elem) ? 0 : -1;
    } else {
        int left_index = linearIndexArray(array, num_elem/2, elem);
        if (left_index != -1) {
            return left_index;
        }
        int right_index = linearIndexArray(array + num_elem/2, num_elem - num_elem/2, elem);
        if (right_index != -1)  {
            return num_elem/2 + right_index;
        }
        return -1;
    }
}

int main() {
    double array[] = {4.64, 4.6, 5.6};
    // bool result = linearSearchArray(array, sizeof(array)/sizeof(double), 4.6);
    int index = linearIndexArray(array, sizeof(array)/sizeof(double), 4.6);
    cout << "Element found at index: " << index << endl;
    return 0;
}