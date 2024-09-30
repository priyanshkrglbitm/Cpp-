#include<bits/stdc++.h>
using namespace std;

// Optimised Solution
class Solution {
public:
    int longestCommonSubsequence(string &s,string &t)
    {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(),s.end());
        return longestCommonSubsequence(s,t);
    }
};

// Normal Solution
bool isPalindrome(string &s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

// if not circular no need to extend string and j loop will run from to i  to n
int longestCircularPalindrome(string &s) {
    
    int n = s.size();
    string extendedString = s + s;  
    int maxLength = 0;

    for (int i = 0; i < n; ++i) {  
        for (int j = i; j < i + n; ++j) {
            if (isPalindrome(extendedString, i, j)) {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}

int main() {
    string s = "Antman";
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout<<s<<endl;
    int result = longestCircularPalindrome(s);
    std::cout << "The length of the longest palindromic substring in circular fashion is: " << result << std::endl;
    return 0;
}
