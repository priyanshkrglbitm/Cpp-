#include <iostream>
#include <string>
using namespace std;

int minTurnsToSeparateXY(string s) {
    int changes1 = 0, changes2 = 0;
    int n = s.size();

    string s1 = s;  
    string s2 = s;  

    // Calculate changes by iterating from left to right
    for (int i = 0; i < n - 1; ++i) {
        if (s1[i] == s1[i + 1]) {
            ++changes1;
            s1[i + 1] = (s1[i] == 'x') ? 'y' : 'x';
        }
    }

    // Calculate changes by iterating from right to left
    for (int j = n - 1; j > 0; --j) {
        if (s2[j] == s2[j - 1]) {
            ++changes2;
            s2[j - 1] = (s2[j] == 'x') ? 'y' : 'x';
        }
    }

    return min(changes1, changes2);
}

int main() {
    string input;
    cout << "Enter the string: ";
    cin >> input;

    int result = minTurnsToSeparateXY(input);
    cout << "Output: " << result << endl;

    return 0;
}
