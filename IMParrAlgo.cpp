#include<bits/stdc++.h>
using namespace std;

// // C++ STL provides toupper() and tolower() functions to convert to uppercase and lowercase respectively.

void displayArray(vector<int>&arr){
    cout<<"[ ";
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<" ]"<<endl;
}

bool caseInsensitiveCompare(const std::string &a, const std::string &b) {
    return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), 
        [](char a, char b) {
            return tolower(a) < tolower(b);
        });
}


bool customCompare(const std::string &a, const std::string &b) {
    if (tolower(a[0]) == tolower(b[0])) {
        return (isupper(a[0]) && islower(b[0])) || (a < b);
    }
    return tolower(a[0]) < tolower(b[0]);
}

int main()
{
	int arr[] = {10, 20, 5, 23 ,42 , 15, 20};
	int n = sizeof(arr)/sizeof(arr[0]);
	vector<int> vect(arr, arr+n); // Putting array into vector

    displayArray(vect);

	// Sorting the Vector in Ascending order
	sort(vect.begin(), vect.end());

	cout << "Vector after sorting is: ";
	displayArray(vect);


	// Sorting the Vector in Descending order
	sort(vect.begin(),vect.end(), greater<int>());
    cout << "Vector after sorting in Descending order is: ";
	displayArray(vect);


	// Reversing the Vector 
	reverse(vect.begin(), vect.end());
    cout << "Vector after reversing is: ";
	displayArray(vect);

	cout << "Maximum element of vector is: ";
	cout << *max_element(vect.begin(), vect.end())<<endl;;

	cout << "Minimum element of vector is: ";
	cout << *min_element(vect.begin(), vect.end())<<endl;

	// Starting the summation from 0
	cout << "The summation of vector elements is: ";
	cout << accumulate(vect.begin(), vect.end(), 0)<<endl; // 0 is starting index

    cout << "Occurrences of 20 in vector : ";
    // Counts the occurrences of 20 from 1st to last element
    cout << count(vect.begin(), vect.end(), 20);
 
    // find() returns iterator to last address if element not present
    find(vect.begin(), vect.end(),5) != vect.end()? cout << "Element found"<<endl : cout << "\nElement not found"<<endl;

 
    // Returns the first occurrence of 20
    auto q = lower_bound(vect.begin(), vect.end(), 20);
 
    // Returns the last occurrence of 20
    auto p = upper_bound(vect.begin(), vect.end(), 20);
 
    cout << "The lower bound is at position: ";
    cout << q-vect.begin() << endl;
 
    cout << "The upper bound is at position: ";
    cout << p-vect.begin() << endl;

    vect.erase(find(vect.begin(),vect.end(),10));
    displayArray(vect);

    vect.resize(8); // simple resize vector with remaining value set to 0 by default
    vect.resize(10,100); // resize with remaining value set to you want
    vect.resize(5); // shorten the size


    string s="Hel";
    do{
        cout<<s<<" ";
    }
    while(next_permutation(s.begin(),s.end()));

	return 0;

    // lexicogrpahically : for that simple use sort() it will also do the job

    vector<string> strings = {"apple", "Banana", "orange", "Apple", "grape"};

    sort(strings.begin(), strings.end(), caseInsensitiveCompare);

    std::cout << "Strings in case-insensitive lexicographical order:\n";
    for (const auto& str : strings) {
        std::cout << str << "\n";
    }

    vector<string> strings = {"apple", "Banana", "orange", "Apple", "grape"};

    std::sort(strings.begin(), strings.end(), customCompare);

    std::cout << "Strings in custom lexicographical order:\n";
    for (const auto& str : strings) {
        std::cout << str << "\n";
    }

}
