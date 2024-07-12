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

class Solution {
public:
    //Function to return max value that can be put in knapsack of capacity c.
    int knapSack(int c, vector<int>& wt, vector<int>& val) {
        int n = wt.size() + 1;
        c = c + 1;
        int** dp = new int*[n];
        for (int i = 0; i < n; i++) {
            dp[i] = new int[c];
            fill_n(dp[i], c, 0);
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < c; j++) {
                if (wt[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
                }
                printArray(dp, n, c);
            }
        }
        int res = dp[n-1][c-1];
        for (int i = 0; i < n; i++) {
            delete[] dp[i];
        }
        delete[] dp;

        return res;
    }
};

int main() {
    Solution sol = Solution();
    int c = 0;
    vector<int> wt = {3};
    vector<int> val = {2};
    int res = sol.knapSack(c, wt, val);
    cout << res << endl;
    return 0;
}