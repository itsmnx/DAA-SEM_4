#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter size of character array: ";
    cin >> n;

    vector<char> chars(n);
    cout << "Enter characters (space-separated): ";
    for (int i = 0; i < n; i++) {
        cin >> chars[i];
    }

    // Frequency array for ASCII (256 possible characters)
    int freq[256] = {0};

    // Count frequency of each character
    for (char c : chars) {
        freq[(unsigned char)c]++;
    }

    cout << "Characters with their frequencies in alphabetical order:\n";
    // Print characters in alphabetical order
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            cout << (char)i << " : " << freq[i] << "\n";
        }
    }

    return 0;
}
