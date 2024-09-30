#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
int uniquePathRecursive(int m , int n){
    if(m==0 && n==0) return 1;
    if(m<0 || n<0) return 0;
    int up=uniquePathRecursive(m-1,n);
    int left=uniquePathRecursive(m,n-1);
    return up+left;
}

int uniquePathUtil(int m, int n, vector<vector<int>>& dp) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                // Base case: start point
                dp[i][j] = 1;
            } else {
                int up = 0, left = 0;
                if (i > 0) {
                    up = dp[i - 1][j]; 
                }
                if (j > 0) {
                    left = dp[i][j - 1];
                }
                dp[i][j] = up + left; 
            }
        }
    }
    return dp[m - 1][n - 1];
}

int uniquePathTabulation(int m, int n) {
    // Create a dp table to store the results of subproblems
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Call the utility function to fill the dp table
    return uniquePathUtil(m, n, dp);
}

int main() {
    int rows, cols;
    cout << "Enter Total Rows: ";
    cin >> rows;
    cout << "Enter Total Cols: ";
    cin >> cols;
    
    int ans = uniquePathTabulation(rows, cols);
    cout << "Number of unique paths: " << ans << endl;

    return 0;
}
