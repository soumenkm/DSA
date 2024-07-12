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
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size() - 1;
        if (n < 2) {
            throw runtime_error("nums has to be at least 2");
        }
        int** dp = new int*[n];
        for (int i = 0; i < n; i++) {
            dp[i] = new int[n];
            fill_n(dp[i], n, 0);
        }

        for (int d = 1; d < n; d++) {
            for (int i = 0; i < n-d; i++) {
                int j = d+i;
                int maxVal = INT32_MIN;
                for (int k = i; k < j; k++) {
                    int val = dp[i][k] + dp[k+1][j] + nums[i]*nums[k+1]*nums[j+1];
                    if (val > maxVal) {
                        maxVal = val;
                    }
                }
                dp[i][j] = maxVal;
                printArray(dp, n, n);
            }
        }
        int result = dp[0][n-1];
        
        for (int i = 0; i < n; i++) {
            delete[] dp[i];
            dp[i] = nullptr;
        }
        delete[] dp;
        dp = nullptr;

        return result;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {1};
    int res = sol.maxCoins(nums);
    cout << res << endl;
    return 0;
}