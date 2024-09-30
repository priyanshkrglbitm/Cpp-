#include <bits/stdc++.h>
using namespace std;

int fibDPUsingMemoization(int n, vector<int> &dp) {
    if (n <= 1) return n;

    if (dp[n] != -1) return dp[n];

    return dp[n] = fibDPUsingMemoization(n - 1, dp) + fibDPUsingMemoization(n - 2, dp);
}

int fibDPUsingTabulation(int n) {
    vector<int> dp1(n+1); 
    dp1[0] = 0; // Fibonacci(0)
    dp1[1] = 1; // Fibonacci(1)
    
    for (int i = 2; i <= n; i++) {
        dp1[i] = dp1[i - 1] + dp1[i - 2];
    }

    return dp1[n];
}

int main() {
    int n;
    cout << "Enter the number of terms for Fibonacci series: ";
    cin >> n;

    vector<int> dp(n+1 , -1); // Initialize vector with size n+1 and fill it with -1

    cout << "Fibonacci of " << n << " using memoization: " << fibDPUsingMemoization(n, dp) << endl;

    int ans = fibDPUsingTabulation(n);
    cout << "Fibonacci of " << n << " using tabulation: " << ans << endl;

    return 0;
}
