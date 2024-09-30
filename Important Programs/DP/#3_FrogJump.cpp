#include <bits/stdc++.h>
using namespace std;

int FrogJumpRecursive(int n, vector<int> &height) {
    if (n == 0) return 0;  // Base case: when the frog is already at the top
    if (n == 1) return abs(height[n] - height[n - 1]);  // Base case: when the frog can jump directly to the top
    int jump2 = FrogJumpRecursive(n - 2, height) + abs(height[n] - height[n - 2]);
    int jump1 = FrogJumpRecursive(n - 1, height) + abs(height[n] - height[n - 1]);
    return min(jump1, jump2);
}

int FrogJumpTabulation(int n, vector<int> &height){
    vector<int> dp(n+1,-1);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int jump2=INT_MAX;
        int jump1=dp[i-1]+abs(height[i]-height[i-1]);
        if(n>1){
            jump2=dp[i-2]+abs(height[i]-height[i-2]);
        }
    return min(jump1,jump2);
    }
    return dp[n];
}

int main() {
    vector<int> height = {10, 30, 50, 10,30};
    int n = 5;
    cout << "Minimum Energy Required by Frog to Reach Top is: " << FrogJumpRecursive(n - 1, height);
    return 0;
}
