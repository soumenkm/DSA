#include <iostream>
#include <vector>
using namespace std;

void printArray(int** array, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

class Solution{   
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int s = sum+1;
        int n = arr.size() + 1;
        int** dp = new int*[n];
        for (int i = 0; i < n; i++) {
            dp[i] = new int[s];
            fill_n(dp[i], s, -1);
        }
        fill_n(dp[0], s, 0);
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < s; j++) {
                if (arr[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = static_cast<bool>(dp[i-1][j-arr[i-1]]) || static_cast<bool>(dp[i-1][j]);
                }
                printArray(dp, n, s);
            }
        }
        int result = dp[n-1][s-1];
        for (int i = 0; i < n; i++) {
            delete[] dp[i];
        }
        delete[] dp;
        return result;   
    }
};

int main() {
    Solution sol = Solution();
    vector<int> arr = {3, 4, 5, 2};
    int sum = 6;
    bool res = sol.isSubsetSum(arr, sum);
    cout << res << endl;
    return 0;
}