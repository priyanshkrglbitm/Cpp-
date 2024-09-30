#include<bits/stdc++.h>
using namespace std;

bool caseInsensitiveCompare(const string &a, const string &b) {
    return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(),
        [](char a, char b) {
            return tolower(a) < tolower(b);
        });
}

int main() {
    vector<string> strings = {"apple", "Banana", "orange", "Apple", "grape","Grape"};

    // Sorting the vector of strings using the case-insensitive comparator
    sort(strings.begin(), strings.end(), caseInsensitiveCompare);

    cout << "Strings in case-insensitive lexicographical order:"<<endl;
    for (const auto& str : strings) {
        std::cout << str <<endl;
    }
    return 0;
}
