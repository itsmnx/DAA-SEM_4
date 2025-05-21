#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool hasDuplicateInWindow(const vector<int>& arr, int k) {
    unordered_set<int> windowSet;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        // If duplicate found in the current window
        if (windowSet.find(arr[i]) != windowSet.end()) {
            return true;
        }

        windowSet.insert(arr[i]);

        // Remove the element which is out of current window size k
        if (i >= k) {
            windowSet.erase(arr[i - k]);
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int k;
        cin >> k;

        if (hasDuplicateInWindow(arr, k)) {
            cout << "Duplicate present in window " << k << "\n";
        } else {
            cout << "Duplicate not present in window " << k << "\n";
        }
    }

    return 0;
}
