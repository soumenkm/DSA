#include <iostream>
#include <string>
#include <vector>
using namespace std;

int longestCommonSubsequenceWithoutDP(string text1, string text2) {
    auto begIt1 = text1.cbegin();
    auto begIt2 = text2.cbegin();
    auto endIt1 = text1.cend();
    auto endIt2 = text2.cend();
    int result = {0};

    if (begIt1 == endIt1 || begIt2 == endIt2) {
        // Base case: When any one of the seq is null string
        result = 0;
    } else if (*(endIt1-1) == *(endIt2-1)) {
        // When last char is same for both text1 and text2
        string newText1(begIt1, endIt1-1);
        string newText2(begIt2, endIt2-1);
        result = 1 + longestCommonSubsequenceWithoutDP(newText1, newText2);
    } else {
        // When last char is not same for both the texts
        string newText1(begIt1, endIt1-1);
        string newText2(begIt2, endIt2-1);
        int result1 = longestCommonSubsequenceWithoutDP(text1, newText2);
        int result2 = longestCommonSubsequenceWithoutDP(newText1, text2);
        result = max(result1, result2);
    }
    cout << text1 << " " << text2 << " " << result << endl;
    return result;
}

class Solution {
public:
    int** dp = nullptr;
    int longestCommonSubsequence(string text1, string text2) {
        dp = new int*[text1.size()]{nullptr};
        for (int i = 0; i < text1.size(); i++) {
            dp[i] = new int[text2.size()]{0};
            for (int j = 0; j < text2.size(); j++) {
                dp[i][j] = -1;
            }
        }
        int res = helper(text1, text2, text1.size(), text2.size());
        for (int i = 0; i < text1.size(); i++) {
            delete[] dp[i];
            dp[i] = nullptr;
        }
        delete[] dp;
        dp = nullptr;
        return res;
    }
    int helper(string& text1, string& text2, int m, int n) {
        int result = {0};

        // Guard
        if (m > 0 && n > 0 && dp[m-1][n-1] != -1) {
            return dp[m-1][n-1];
        }

        if (m == 0 || n == 0) {
            // Base case: When any one of the seq is null string
            result = 0;
        } else if (text1[m-1] == text2[n-1]) {
            // When last char is same for both text1 and text2
            result = 1 + helper(text1, text2, m-1, n-1);
        } else {
            // When last char is not same for both the texts
            int result1 = helper(text1, text2, m, n-1);
            int result2 = helper(text1, text2, m-1, n);
            result = max(result1, result2);
        }
        if (m > 0 && n > 0) {
            dp[m-1][n-1] = result;
        }
        cout << text1 << " " << text2 << result;
        return result;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> vec1 = {"abcde", "abc", "abc"};
    vector<string> vec2 = {"ace", "abc", "def"};
    for (int i = 0; i < vec1.size(); i++) {
        int res = sol.longestCommonSubsequence(vec1[i], vec2[i]);
        cout << "Length of LCS(" << vec1[i] <<  ", " << vec2[i] << ") = " << res << endl;
    }
    return 0; 
}