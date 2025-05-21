#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void generatePermutations(const string &inputStr, vector<bool> &usedFlags, string &currentPermutation, vector<string> &allPermutations) {
    if (currentPermutation.size() == inputStr.size()) {
        allPermutations.push_back(currentPermutation);
        return;
    }

    for (int index = 0; index < inputStr.size(); index++) {
        // Skip already used characters
        if (usedFlags[index]) 
            continue;

        // Skip duplicates (only if previous same char is not used in this recursion level)
        if (index > 0 && inputStr[index] == inputStr[index - 1] && !usedFlags[index - 1]) 
            continue;

        usedFlags[index] = true;
        currentPermutation.push_back(inputStr[index]);
        generatePermutations(inputStr, usedFlags, currentPermutation, allPermutations);
        currentPermutation.pop_back();
        usedFlags[index] = false;
    }
}

int main() {
    string inputString;
    cout << "Enter string: ";
    cin >> inputString;

    // Sort string to ensure permutations are generated in lexicographic order
    sort(inputString.begin(), inputString.end());

    vector<bool> usedFlags(inputString.size(), false);
    vector<string> allPermutations;
    string currentPermutation;

    generatePermutations(inputString, usedFlags, currentPermutation, allPermutations);

    cout << "All permutations in lexicographic order:\n";
    for (const string &permutation : allPermutations) {
        cout << permutation << "\n";
    }

    return 0;
}
