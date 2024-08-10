#include <bits/stdc++.h>
using namespace std;

void printMaxSubarray(const vector<int>& arr, int start, int end) {
    cout << "[ ";
    for (int i = start; i <= end; i++) { 
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}
// Brute Force Approach
int maxSumSubarrayBruteForce(const vector<int>& arr) {
    int n = arr.size();
    int start_index = 0, end_index = 0;
    if (n == 0) return 0;

    int max_sum = INT_MIN; 

    for (int i = 0; i < n; ++i) {
        int current_sum = 0;

        for (int j = i; j < n; ++j) { 
            current_sum += arr[j];
            if (current_sum > max_sum) {
                max_sum = current_sum;
                start_index = i;
                end_index = j; // Correctly set end_index to j
            }
        }
    }

    printMaxSubarray(arr, start_index, end_index);
    return max_sum;
}

// Kadane Algorithm
int maxSumSubarrayKadane(const vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0; 

    int max_sum = INT_MIN;
    int current_sum = 0;
    int start_index = 0, end_index = 0, temp_start = 0;

    for (int i = 0; i < n; ++i) {
        current_sum += arr[i];

        if (current_sum > max_sum) {
            max_sum = current_sum;
            start_index = temp_start;
            end_index = i;
        }

        // Reset current_sum and update temp_start if current_sum drops below 0
        if (current_sum < 0) {
            current_sum = 0;
            temp_start = i + 1;
        }
    }

    printMaxSubarray(arr, start_index, end_index);
    return max_sum;
}

int main() {
    vector<int> arr = {1, -2, 3, 4, -1, 2, 1, -5, 4};

    int max_sum = maxSumSubarrayBruteForce(arr);

    cout << "Maximum sum of any subarray is: " << max_sum << endl;

    return 0;
}
