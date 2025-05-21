#include <iostream>
#include <vector>
#include <string>
using namespace std;

string printLCS(const string& X, const string& Y, const vector<vector<int>>& dp) {
    int i = X.size();
    int j = Y.size();
    string lcs = "";

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;  // add current char to LCS
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    return lcs;
}

int main() {
    string X, Y;
    cout << "Enter first sequence: ";
    cin >> X;
    cout << "Enter second sequence: ";
    cin >> Y;

    int m = X.size();
    int n = Y.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string lcs = printLCS(X, Y, dp);

    cout << "Length of Longest Common Subsequence: " << dp[m][n] << endl;
    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
