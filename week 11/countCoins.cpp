#include <iostream>
#include <vector>

using namespace std;

int countWaysToMakeSum(const vector<int>& coins, int N) {
    vector<int> dp(N + 1, 0);
    dp[0] = 1;  // base case

    for (int coin : coins) {
        for (int i = coin; i <= N; i++) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[N];
}

int main() {
    int n;
    cout << "Enter number of coins: ";
    cin >> n;
    vector<int> coins(n);

    cout << "Enter coin values:\n";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int N;
    cout << "Enter sum value N: ";
    cin >> N;

    int ways = countWaysToMakeSum(coins, N);
    cout << "Number of ways to make sum " << N << " is: " << ways << endl;

    return 0;
}
