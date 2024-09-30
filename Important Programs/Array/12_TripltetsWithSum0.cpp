#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


// Brute Force Approach
void printTripletsWithSumZero(const std::vector<int>& nums) {
    int n = nums.size();

    // Check every triplet using three nested loops
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    cout<< nums[i] << ", " << nums[j] << ", " << nums[k]<<endl;
                }
            }
        }
    }
}

//Optimised Approach
void printTripletsWithSumZero(std::vector<int>& nums) {
    int n = nums.size();
    
    // Sort the array
    sort(nums.begin(), nums.end());

    // Traverse the array
    for (int i = 0; i < n - 2; ++i) {
        // Avoid duplicates
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                cout << nums[i] << ", " << nums[left] << ", " << nums[right] << std::endl;
                
                // Move both pointers and avoid duplicates
                while (left < right && nums[left] == nums[left + 1]) ++left;
                while (left < right && nums[right] == nums[right - 1]) --right;
                
                ++left;
                --right;
            } else if (sum < 0) {
                ++left;
            } else {
                --right;
            }
        }
    }
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    cout << "Triplets with sum zero:\n";
    printTripletsWithSumZero(nums);

    return 0;
}
