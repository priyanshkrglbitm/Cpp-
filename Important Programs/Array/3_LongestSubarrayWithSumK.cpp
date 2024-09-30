#include <iostream>
#include <vector>
using namespace std;

// Brute Force Approach
int maxLengthSubarrayWithSumK(vector<int> arr, int k) {
    int n = arr.size();
    int max_length = 0;
    int start_index = 0; 
    int end_index = 0;   

    for (int i = 0; i < n; ++i) {
        int current_sum = 0;

        for (int j = i; j < n; ++j) {
            current_sum += arr[j]; 

            if (current_sum == k) {
                int length = j - i + 1;
                if (length > max_length) {
                    max_length = length;
                    start_index = i; // Keeping start index and end_index of maximum subarray , if I'm told to print i can
                    end_index = j;
                }
            }
        }
    }
    return max_length;
}

// Optimal Approach
int maxLengthSubarrayWithSumK(vector<int> arr, int k) {
    int n = arr.size();
    int maxLen = 0;
    int left = 0; 
    int current_sum = 0;

    for (int right = 0; right < n; right++) {
        current_sum += arr[right]; // Expand the window by including arr[right]

        // Shrink the window from the left if current_sum exceeds k
        while (current_sum > k && left <= right) {
            current_sum -= arr[left];
            ++left;
        }

        // Check if current_sum equals k
        if (current_sum == k) {
            int length = right - left + 1;
            maxLen = max(maxLen, length);
        }
    }

    return maxLen;
}



int main() {
    vector<int> arr = {1, -1, 5, -2, 3};
    int k = 3;

    int length = maxLengthSubarrayWithSumK(arr, k);

    cout << "Length of the longest subarray with sum " << k << " is: " << length << endl;

    return 0;
}
