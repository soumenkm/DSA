#include <iostream>
#include <vector>
using namespace std;

int fib(const int n, int* const array) {
    if (array[n] != 0) {
        return array[n];
    }
    int res = {0};
    if (n == 0 || n == 1) {
        res = 1;
    } else {
        res = fib(n-1, array) + fib(n-2, array);
    }
    array[n] = res;
    return res;
}

int fibV(const int n) {
    static vector<int> array(n+1, 0);
    if (array[n] != 0) {
        return array[n];
    }
    int res = {0};
    if (n == 0 || n == 1) {
        res = 1;
    } else {
        res = fibV(n-1) + fibV(n-2);
    }
    array[n] = res;
    return res;
}
int main() {
    int n = 8;
    // since the fib is called multiple times, handle the memory management outside of fib function
    // so the fib function takes an additional array argument. We could have done all these using
    // STL vector which manages memory automatically.
    // int* array = new int[n+1]{0};
    // int res = fib(n, array);
    // cout << "Result: " << res << endl;
    // delete[] array;
    // array = nullptr;

    cout << fibV(n) << endl;

    return 0;
}