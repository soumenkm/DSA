#include <iostream>
using namespace std;

double findSumArray(const double* const array, const int num_elem) {
    if (num_elem <= 0) {
        throw runtime_error("Num of elem must be at least 1");
    } else if (num_elem == 1) {
        return array[0];
    } else {
        double sum_left = findSumArray(array, num_elem/2);
        // array+5 is a temp value which cannot be applied a top level const decltype(array+5): const double*
        double sum_right = findSumArray(array + num_elem/2, num_elem - num_elem / 2); 
        double result = sum_left + sum_right;
        return result;
    }
}

int main() {
    double array[] = {5.5, 10.5, 4.6};
    double result = findSumArray(array, sizeof(array)/sizeof(double));
    cout << "Array sum: " << result << endl;
    return 0;
}