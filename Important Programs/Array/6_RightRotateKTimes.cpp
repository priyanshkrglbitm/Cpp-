#include <bits/stdc++.h>
using namespace std;

void rightRotateKTimes(vector<int>& arr, int k) {
    int n = arr.size();
    if (k == n || k == 0) return;

    k = k % n; 

    vector<int> temp;

    for (int i = n - k; i < n; i++) {
        temp.push_back(arr[i]);
    }

    for (int i = n - 1; i >= k; i--) {
        arr[i] = arr[i - k];
    }

    for (int j = 0; j < temp.size(); j++) {
        arr[j] = temp[j];
    }
}

//Optimised
void rightRotateKTimes(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;

    // Reverse the entire array
    reverse(arr.begin(), arr.end());

    // Reverse the first k elements
    reverse(arr.begin(), arr.begin() + k);

    // Reverse the remaining elements
    reverse(arr.begin() + k, arr.end());
}

int main() {
    vector<int> arr = {2, 4, 5, 6, 7, 1};
    int k = 3;
    rightRotateKTimes(arr, k);
    for (auto it : arr) {
        cout << it << " ";
    }
    return 0;
}
