#include <bits/stdc++.h>
using namespace std;

// Recursive function to find the shortest path sum
int shortestPathRecursive(vector<vector<int>>& grid, int rows, int cols) {

    if (rows == 0 && cols == 0) {
        return grid[0][0];
    }

    if (rows < 0 || cols < 0) {
        return INT_MAX;
    }

    int up = shortestPathRecursive(grid, rows - 1, cols);
    int left = shortestPathRecursive(grid, rows, cols - 1);
    
    
    return grid[rows][cols] + min(up, left);
}

int shortestPathMemoization(vector<vector<int>>& grid, int rows, int cols,vector<vector<int>>& dp){
    if(rows==0 && cols==0 )return grid[0][0];
    if(rows<0 || cols<0) return INT_MAX;
    if(dp[rows][cols]!=-1)return dp[rows][cols];

    int up=grid[rows][cols]+shortestPathMemoization(grid,rows-1,cols,dp);
    int left=grid[rows][cols]+shortestPathMemoization(grid,rows,cols-1,dp);
    return dp[rows][cols]=min(up,left);
}

int main() {
    vector<vector<int>> grid = {
        {1, 5, 8},
        {4, 7, 1},
        {5, 2, 6}
    };
    
    int ansR = shortestPathRecursive(grid, 2, 2); // Start from bottom-right corner (2, 2)
    cout << "Shortest Path Sum: " << ansR << endl;
    vector<vector<int>>dp(3,vector<int>(3,-1));
    int ansM=shortestPathMemoization(grid,2,2,dp);
    cout << "Shortest Path Sum: " << ansR << endl;
    return 0;
}
