#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find majority candidate using Boyer-Moore Voting
int findMajorityCandidate(const vector<int>& arr) {
    int count = 0, candidate = 0;
    for (int num : arr) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }
    return candidate;
}

// Verify if candidate is majority element
bool isMajority(const vector<int>& arr, int candidate) {
    int count = 0;
    for (int num : arr) {
        if (num == candidate) count++;
    }
    return count > arr.size() / 2;
}

// Find median after sorting
double findMedian(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if (n % 2 == 1)
        return arr[n / 2];
    else
        return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int candidate = findMajorityCandidate(arr);
    if (isMajority(arr, candidate))
        cout << "Majority element exists: " << candidate << endl;
    else
        cout << "No majority element exists." << endl;

    double median = findMedian(arr);
    cout << "Median of the array is: " << median << endl;

    return 0;
}
