#include <bits/stdc++.h>
using namespace std;

//Recursive Approach
int helperRecursive(vector<vector<int>>& points, int day, int prevActivity) {
    if (day < 0) return 0;  // Base case: No more days left

    int maxx = 0;
    for (int i = 0; i < 3; i++) {  // Loop through all 3 activities
        if (i != prevActivity) {
            int pointsEarned = points[day][i] + helperRecursive(points, day - 1, i);
            maxx = max(maxx, pointsEarned);
        }
    }
    return maxx;
}

int ninjaTrainingRecursive(int n, vector<vector<int>>& points) {
    if (n == 0) return 0;
    return helperRecursive(points, n - 1, -1);  // Start with the last day and no previous activity constraint
}

int helperMemoization(vector<vector<int>>& points, int day, int prevActivity, vector<vector<int>>& dp) {
    if (day < 0) return 0;  
    
    // If this subproblem has already been solved, return the stored result
    if (dp[day][prevActivity] != -1) {
        return dp[day][prevActivity];
    }

    int maxx = 0;
    for (int i = 0; i < 3; i++) {  // Loop through all 3 activities
        if (i != prevActivity) {
            int pointsEarned = points[day][i] + helperMemoization(points, day - 1, i, dp);
            maxx = max(maxx, pointsEarned);
        }
    }
    // Store the result of this subproblem
    return dp[day][prevActivity] = maxx;
}

int ninjaTrainingMemoization(int n, vector<vector<int>>& points) {
    if (n == 0) return 0;

    vector<vector<int>> dp(n, vector<int>(4, -1)); // 1 extra index to store no activities performed
 
    return helperMemoization(points, n - 1, 3, dp);
}

int main() {
    vector<vector<int>> points = {
        {2, 1, 3},
        {3 , 4, 6},
        {10 , 1 , 6},
        {8 , 3 , 7}
    };

    int n = points.size();  
    cout << ninjaTrainingRecursive(n, points);
}
