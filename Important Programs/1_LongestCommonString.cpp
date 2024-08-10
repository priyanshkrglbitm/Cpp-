#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Brute Force
int longestCommonSubstringBruteForce(const string& s1, const string& s2) {
    int maxLength = 0;
    int m = s1.size();
    int n = s2.size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int length = 0;

            while (i + length < m && j + length < n && s1[i + length] == s2[j + length]) {
                ++length;
            }

            maxLength = max(maxLength, length);
        }
    }

    return maxLength;
}

// Most Optimal Solution.
int longestCommonSubstring(const string& s1, const string& s2) {
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int maxLength = 0; 

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                maxLength = max(maxLength, dp[i][j]);
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    return maxLength;
}


int main() {
    string s1 = "ROMANINROMES";
    string s2 = "XMANBATANINROMY";

    int result = longestCommonSubstring(s1, s2);
    cout << "Length of the longest common substring: " << result << endl;

    return 0;
}
