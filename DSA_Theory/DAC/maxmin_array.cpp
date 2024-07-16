#include <iostream>
#include <vector>
using namespace std;

vector<double> findMaxMinArray(const double* const array, const int num_elem) {
    if (num_elem <= 0) {
        throw runtime_error("The num of elem must be at least 1");
    } else if (num_elem == 1) {
        vector<double> result = {array[0], array[0]};
        return result;
    } else {
        int num_elem_left = num_elem / 2;
        int num_elem_right = num_elem - num_elem_left;
        const double* array_left = array;
        const double* array_right = array + num_elem_left;
        
        vector<double> result_left = findMaxMinArray(array_left, num_elem_left);
        vector<double> result_right = findMaxMinArray(array_right, num_elem_right);
        vector<double> result = {0, 0};
        
        if (result_left.at(0) < result_right.at(0)) {
            result.at(0) = result_right.at(0);
        } else {
            result.at(0) = result_left.at(0);
        }
        if (result_left.at(1) < result_right.at(1)) {
            result.at(1) = result_left.at(1);
        } else {
            result.at(1) = result_right.at(1);
        }
        return result;
    }
}

int main() {
    double array[] = {10.3, 34.5, 53.4, 56.6, -54.5};
    int num_elem = sizeof(array)/sizeof(double);
    vector<double> result = findMaxMinArray(array, num_elem);
    cout << "Max: " << result.at(0) << ", Min: " << result.at(1) << endl;
    return 0;
}