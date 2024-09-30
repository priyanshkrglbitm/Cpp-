#include<bits/stdc++.h>
using namespace std;

int uniquePathRecursive(int r, int c, int m, int n, vector<vector<bool>>& visited) {
    // Base case: Reached the starting point
    if (r == 0 && c == 0) return 1;
    
    if (r < 0 || c < 0 || c >= n || visited[r][c]) return 0; // r<0 checks doesnot go out of bound from top  , c<0 for left , c>=n for right

    // Mark the current cell as visited
    visited[r][c] = true;

    int up = uniquePathRecursive(r - 1, c, m, n, visited);
    int left = uniquePathRecursive(r, c - 1, m, n, visited);
    int right = uniquePathRecursive(r, c + 1, m, n, visited);

    // Backtrack: unmark the current cell
    visited[r][c] = false;

    return up + left + right;
}

// Memoized recursive function

// In this we dont need a visited matrix because dp will avoid calculation of path which is  already computed.
int uniquePathMemoization(int r, int c, vector<vector<int>>& dp) {

    if (r == 0 && c == 0) return 1;

    if (r < 0 || c < 0) return 0;

    if (dp[r][c] != -1) return dp[r][c];

    int up = uniquePathMemoization(r - 1, c, dp);
    int left = uniquePathMemoization(r, c - 1, dp);
    int right = uniquePathMemoization(r, c + 1, dp);

    return dp[r][c] = up + left + right;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return uniquePathMemoization(m - 1, n - 1, dp);
}

int main(){
    int rows , cols;
    cout<<"Enter Rows : ";
    cin>>rows;
    cout<<"Enter Cols : ";
    cin>>cols;
    int ans=uniquePaths(rows,cols);
    cout<<ans;
}