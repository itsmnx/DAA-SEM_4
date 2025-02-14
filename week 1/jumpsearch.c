#include <stdio.h>
#include <math.h>

void jumpsearch(int arr[], int n, int key) {
    int start = 0;
    int jump = sqrt(n);
    while (start < n && arr[start] < key) {
        if (arr[jump] >= key || jump >= n) {
            break;
        }
        start = jump;
        jump += sqrt(n);
        if (jump > n - 1) {
            jump = n; 
        }
    }

    for (int i = start; i < jump; i++) {
        if (arr[i] == key) {
            printf("Element found at index %d\n", i);
            return;
        }
    }

    printf("Element not found!\n");
}

int main() {
    int test;
    printf("Enter the number of test cases!\n");
    scanf("%d", &test);

    while (test--) {
        int n;
        printf("Enter the array size!\n");
        scanf("%d", &n);
        int arr[n];

        printf("Enter the array elements in sorted order!\n");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int key;
        printf("Enter the key to be searched in array!\n");
        scanf("%d", &key);

        jumpsearch(arr, n, key);
    }

    return 0;
}
