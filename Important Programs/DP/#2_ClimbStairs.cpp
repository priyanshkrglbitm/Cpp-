#include <bits/stdc++.h>
using namespace std;

// Same as fibonacci but here base condition is changed from dp[0]=0 to dp[0]=1
// Here we use dp(n+1) becuase for n=0 stairs base condition must return 0 which is extra condition


// Tabulation approach (iterative dynamic programming)
int climbStairsTabulation(int n) {
    if (n == 0 || n == 1) return 1;
    if (n == 2) return 2;
    
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Memoization approach (recursive with memoization)
int helperOfMemoization(int n, vector<int> &dp) {
    if (n == 0 || n == 1) return 1;
    if (n == 2) return 2;

    if (dp[n] != -1) return dp[n];
    dp[n] = helperOfMemoization(n - 1, dp) + helperOfMemoization(n - 2, dp);
    return dp[n];
}


int climbStairsMemoization(int n) {
    vector<int> dp(n + 1, -1); // here n+1 is because if stairs is 4 then dp[5] will store answer for 4 stairs.
    return helperOfMemoization(n, dp);
}

int main() {
    int n;
    cout << "Enter number of Stairs: ";
    cin >> n;
    
    cout << "Number of possible ways to reach are (by Tabulation): " << climbStairsTabulation(n) << "\n";
    cout << "Number of possible ways to reach are (by Memoization): " << climbStairsMemoization(n) << "\n";
    
    return 0;
}
