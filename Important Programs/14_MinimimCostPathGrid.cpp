#include <bits/stdc++.h>
using namespace std;

// Function to return the cost of the minimum cost path from (0,0) to (m, n) in a cost matrix
int minCost(vector<vector<int>>& cost, int m, int n) {
    if (m < 0 || n < 0)
        return INT_MAX;
    if (m == 0 && n == 0)
        return cost[m][n];

    return cost[m][n] + min({minCost(cost, m, n - 1),    // Move left
                             minCost(cost, m - 1, n),    // Move up
                             minCost(cost, m - 1, n - 1) // Move diagonal
                            });
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    vector<vector<int>> cost(rows, vector<int>(cols));

    cout << "Enter the cost matrix values:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> cost[i][j];
        }
    }

    cout << "Minimum cost: " << minCost(cost, rows - 1, cols - 1) << endl;

    return 0;
}
