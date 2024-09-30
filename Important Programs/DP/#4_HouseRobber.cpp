#include <bits/stdc++.h>
using namespace std;

// Simple Recursion
int maxProfitHelper(vector<int>& house, int n) {
    if (n < 0) return 0;
    if (n == 0) return house[0];
    int pick = house[n] + maxProfitHelper(house, n - 2);
    int notPick = maxProfitHelper(house, n - 1);
    return max(pick, notPick);
}

int maxProfitRecursive(vector<int>& house) {
    int n = house.size();
    int ans = maxProfitHelper(house, n - 1);
    return ans;
}

// Memoization
int solveUtil(vector<int>& house, int n, vector<int>& dp) {
    if (n < 0) return 0;
    if (n == 0) return house[0];
    if (dp[n] != -1) {
        return dp[n];
    }
    int pick = house[n] + solveUtil(house, n - 2, dp);
    int notPick = solveUtil(house, n - 1, dp);
    return dp[n] = max(pick, notPick);
}

int maxProfitMemoization(vector<int>& house) {
    int n = house.size();
    vector<int> dp(n, -1);
    int ans = solveUtil(house, n - 1, dp);
    return ans;
}

int main() {
    vector<int> house = {2, 4, 0, 8, 9, 7};

    // Using the recursive approach
    int ansRecursive = maxProfitRecursive(house);
    cout << "The max profit by robbing house (Recursive) is: " << ansRecursive << endl;

    // Using the memoization approach
    int ansMemoization = maxProfitMemoization(house);
    cout << "The max profit by robbing house (Memoization) is: " << ansMemoization << endl;

    return 0;
}
