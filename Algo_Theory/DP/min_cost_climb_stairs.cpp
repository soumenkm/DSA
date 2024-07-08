#include <vector>
#include <iostream>
using namespace std;

void printVector(vector<int>& vec) {
    auto length = vec.size();
    for (int i = 0; i < length; i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    int minCostClimbingStairsRec(vector<int>& cost) {
        static int orig_length = static_cast<int>(cost.size());
        int length = static_cast<int>(cost.size());
        static vector<int> dp(length, 0);
        int result = {0};

        if (dp[length-1] != 0) {
            return dp[length-1];
        }

        if (length == 1) {
            result = cost[0];
        } else if (length == 2) {
            result = cost[1];
        } else {
            auto bptr = cost.cbegin();
            auto eptr = cost.cend();
            eptr--;
            vector<int> cost1(bptr, eptr); 
            eptr--;
            vector<int> cost2(bptr, eptr);
            int res1 = minCostClimbingStairsRec(cost1);
            int res2 = minCostClimbingStairsRec(cost2);
            result = min(res1, res2) + cost[length-1];
        }
        dp[length-1] = result;
        cout << "index: " << length-1 << " vector: ";
        printVector(dp);
        if (length == orig_length) {
            return min(dp[length-1], dp[length-2]);
        } else {
            return dp[length-1];
        }
    }

    int minCostClimbingStairs(vector<int>& cost) {
        auto length = cost.size();
        vector<int> dp(length, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < length; i++) {
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        }
        return min(dp[length-1], dp[length-2]);
    }
};

int main() {
    Solution sol = Solution();
    vector<int> cost = {10, 1, 1, 15, 2, 30, 3};
    int res = sol.minCostClimbingStairs(cost);
    cout << res << endl;
    return 0;
}