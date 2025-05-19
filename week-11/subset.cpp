#include <iostream>
#include <vector>
using namespace std;

bool canPartition(const vector<int>& nums) {
    int total = 0;
    for (int num : nums)
        total += num;

    // If total sum is odd, cannot partition
    if (total % 2 != 0)
        return false;

    int target = total / 2;
    int n = nums.size();

    // DP array: dp[i] is true if a subset with sum i can be formed
    vector<bool> dp(target + 1, false);
    dp[0] = true; // Base case: zero sum is always possible

    // Fill the DP array
    for (int num : nums) {
        // Iterate backward to avoid using the same number multiple times
        for (int j = target; j >= num; --j) {
            dp[j] = dp[j] || dp[j - num];
        }
    }

    return dp[target];
}

int main() {
    vector<int> nums = {1, 1};

    if (canPartition(nums))
        cout << "Yes, the array can be partitioned into two subsets with equal sum." << endl;
    else
        cout << "No, the array cannot be partitioned into two subsets with equal sum." << endl;

    return 0;
}
