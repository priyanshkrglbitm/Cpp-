#include <bits/stdc++.h>
using namespace std;

void leftRotateKTimes(vector<int>& arr, int k) {
    int n = arr.size();
    if (k == n || k == 0) return; 

    k = k % n;

    vector<int> temp;

    for (int i = 0; i < k; i++) {
        temp.push_back(arr[i]);
    }

    for (int i = 0; i < n - k; i++) {
        arr[i] = arr[i + k];
    }
    
    for (int j = 0; j < temp.size(); j++) {
        arr[n - k + j] = temp[j];
    }
}

// Optimised
void leftRotateKTimes(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n; 

    std::reverse(arr.begin(), arr.begin() + k); // Reverse first k elements

    std::reverse(arr.begin() + k, arr.end());    // Reverse remaining elements
  
    std::reverse(arr.begin(), arr.end());   // Reverse entire array
}

int main() {
    vector<int> arr = {2, 4, 5, 6, 7, 1};
    int k = 3;
    leftRotateKTimes(arr, 2);
    for (auto it : arr) {
        cout << it << " ";
    }
    return 0;
}
