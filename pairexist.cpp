#include <bits/stdc++.h>
using namespace std;

bool hasPairWithSum(vector<int>& arr, int key) {
    int n = arr.size();
    
    sort(arr.begin(), arr.end()); // O(n log n)

    int left = 0, right = n - 1;

    while (left < right) { // O(n)
        int sum = arr[left] + arr[right];

        if (sum == key) {
            cout << "Pair found: " << arr[left] << " and " << arr[right] << endl;
            return true;
        }
        else if (sum < key) {
            left++; 
        }
        else {
            right--;
        }
    }

    cout << "No such pair found." << endl;
    return false;
}

int main() {
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;

    while (T--) {
        int n, key;
        cout << "Enter array size: ";
        cin >> n;
        
        vector<int> arr(n);
        cout << "Enter array elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "Enter the key: ";
        cin >> key;

        hasPairWithSum(arr, key);
    }

    return 0;
}
