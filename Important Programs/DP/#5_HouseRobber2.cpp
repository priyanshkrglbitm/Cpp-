#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Logic is simple take different summation , first one includes first element and exclude
// last to avoid circular house and vice versa.

class Solution {
public:
    int robMemoization(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp1(n, -1);

        // Scenario 1: Rob the first house and skip the last house
        int result1 = maxProfitHelperMemoization(nums, 0, n - 2, dp1);
 
        vector<int>dp2(n,-1);

        // Scenario 2: Skip the first house and rob the last house
        int result2 = maxProfitHelperMemoization(nums, 1, n - 1, dp2);

        return max(result1, result2);
    }
    
private:
    // Helper function for the memoization approach
    int maxProfitHelperMemoization(vector<int>& house, int start, int end, vector<int>& dp) {
        if (end < start) return 0;
        if (end == start) return house[start];
        if (dp[end] != -1) return dp[end];
        
        int pick = house[end] + maxProfitHelperMemoization(house, start, end - 2, dp);
        int notPick = maxProfitHelperMemoization(house, start, end - 1, dp);
        
        return dp[end] = max(pick, notPick);
    }
};



int main(){
    Solution s;
    vector<int> arr={3,5,1,6,8};
    cout<<"Solution with Memoization: "<<s.robMemoization(arr)<<endl;

}