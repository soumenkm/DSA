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
void print1DArray(int* array, int n) {
    for (int j = 0; j < n; j++) {
        cout << array[j] << " ";
    }
    cout << endl;
}

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int s = amount + 1;
        int n = coins.size() + 1;
        int** dp = new int*[n];
        for (int i = 0; i < n; i++) {
            dp[i] = new int[s]{0};
            fill_n(dp[i]+1, s-1, INT32_MAX/2);
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < s; j++) {
                if (coins[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = min(dp[i][j-coins[i-1]]+1, dp[i-1][j]);
                }
                printArray(dp, n, s);
            }
        }
        int res = dp[n-1][s-1] >= INT32_MAX/2 ? -1 : dp[n-1][s-1];

        for (int i = 0; i < n; i++) {
            delete[] dp[i];
        }
        delete[] dp;
        return res;
    }
    int coinChange1DArray(vector<int>& coins, int amount) {
        int s = amount + 1;
        int n = coins.size() + 1;
        int* dp = new int[s]{0};
        fill_n(dp+1, s-1, INT32_MAX/2);

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < s; j++) {
                if (coins[i-1] > j) {
                    dp[j] = dp[j];
                } else {
                    dp[j] = min(dp[j-coins[i-1]]+1, dp[j]);
                }
                print1DArray(dp, s);
            }
        }
        int res = dp[s-1] >= INT32_MAX/2 ? -1 : dp[s-1];

        delete[] dp;
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> coins = {2};
    int amount = 3;
    int res = sol.coinChange1DArray(coins, amount);
    cout << res << endl;
    return 0;
}