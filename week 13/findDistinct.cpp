#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int &x : arr) cin >> x;

    // Map to store product -> pair of indices
    unordered_map<int, pair<int, int>> productMap;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int product = arr[i] * arr[j];

            // If product already exists
            if (productMap.find(product) != productMap.end()) {
                auto p = productMap[product];
                // Ensure all 4 elements are distinct
                if (p.first != i && p.first != j && p.second != i && p.second != j) {
                    cout << "Pair 1: (" << arr[p.first] << ", " << arr[p.second] << ")\n";
                    cout << "Pair 2: (" << arr[i] << ", " << arr[j] << ")\n";
                    return 0;
                }
            } else {
                productMap[product] = {i, j};
            }
        }
    }

    cout << "No such pairs found.\n";
    return 0;
}
