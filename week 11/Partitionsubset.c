#include <stdio.h>
#include <stdbool.h>

bool canPartition(int* nums, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += nums[i];

    // If sum is odd, can't partition into two equal subsets
    if (sum % 2 != 0)
        return false;

    int target = sum / 2;

    // DP array to store whether subset sum j is possible
    bool dp[target + 1];
    for (int i = 0; i <= target; i++)
        dp[i] = false;

    dp[0] = true;  // sum 0 is always possible

    for (int i = 0; i < n; i++) {
        int num = nums[i];
        for (int j = target; j >= num; j--) {
            if (dp[j - num])
                dp[j] = true;
        }
    }

    return dp[target];
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    if (canPartition(nums, n)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }

    return 0;
}
