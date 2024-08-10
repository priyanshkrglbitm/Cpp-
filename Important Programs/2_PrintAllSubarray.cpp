#include <iostream>
#include <vector>

using namespace std;

// O(n^3)
vector<vector<int>> findAllSubarrays1(const vector<int>& arr) {
    vector<vector<int>> allSubarray;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            vector<int> oneRow;
            for (int k = i; k <= j; k++) {
                oneRow.push_back(arr[k]);
            }
            allSubarray.push_back(oneRow);
        }
    }

    return allSubarray; 
}

//O(n2)
vector<vector<int>> findAllSubarrays2(vector<int> arr) {
    int n = arr.size();
    vector<vector<int>> allSubarray;

    for (int i = 0; i < n; i++) {
        vector<int> currentSubarray;

        for (int j = i; j < n; j++) {
            currentSubarray.push_back(arr[j]);
            allSubarray.push_back(currentSubarray);
        }
            
    }

    return allSubarray;
}

int main() {
    vector<int> arr = {1, 2, 3, 4}; 

    vector<vector<int>> subarrays = findAllSubarrays2(arr);

    cout << "All subarrays of the array are:" << endl;
    for (const auto& subarray : subarrays) {
        cout << "[ ";
        for (int num : subarray) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
