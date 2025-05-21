#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChainMultiplication(const vector<int>& dims) {
    int n = dims.size() - 1; // number of matrices
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // l is chain length
    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + dims[i]*dims[k+1]*dims[j+1];
                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> dims(n+1);
    cout << "Enter dimensions of matrices (a b for each matrix):\n";
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (i == 0)
            dims[0] = a;
        dims[i+1] = b;
    }

    int result = matrixChainMultiplication(dims);
    cout << "Minimum number of multiplications is: " << result << endl;

    return 0;
}
