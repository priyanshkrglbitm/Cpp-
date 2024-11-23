#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive
int LISRecursive(vector<int>& nums, int prev, int index) {
    if (index == nums.size()) return 0;

    // Exclude the current element
    int exclude = LISRecursive(nums, prev, index + 1);

    // Include the current element (if it forms a strictly increasing sequence)
    int include = 0;
    if (nums[index] > prev) {
        include = 1 + LISRecursive(nums, nums[index], index + 1);
    }

    return max(exclude, include);
}

// DP
int LISDP(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1); // Initialize LIS of each element as 1

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS Length (DP): " << LISDP(nums) << endl;
    return 0;
}
