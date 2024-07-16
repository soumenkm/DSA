#include <iostream>
using namespace std;

void printArray(const double* const array, const int num_elem) {
    for (int i = 0; i < num_elem; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

bool binarySearchArray(const double* const array, const int num_elem, const double elem) {
    bool result = -1;
    if (num_elem <= 0) {
        throw runtime_error("Num of elem must be at least 1");
    } else if (num_elem == 1) {
        result = (array[0] == elem) ? true : false;
    } else if (array[num_elem/2 - 1] == elem) {
        result = true;
    } else if (elem < array[num_elem/2 - 1]) {
        result = binarySearchArray(array, num_elem/2, elem);
    } else if (elem > array[num_elem/2 - 1]) {
        result = binarySearchArray(array + num_elem/2, num_elem - num_elem/2, elem);
    }
    // printArray(array, num_elem);
    // cout << result << endl;
    return result;
}

int main() {
    double array[] = {0.1, 10.1, 20.1, 30.1, 40.1, 50.1, 60.1, 70.1, 80.1};
    bool result = binarySearchArray(array, sizeof(array)/sizeof(double), 70.1);
    cout << "Element found: " << result << endl;
    return 0;
}