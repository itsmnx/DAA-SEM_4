#include <stdio.h>
void linearsearch(int arr[], int n, int key) {
    if (n <= 0) {
        printf("Invalid array size!\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at index %d\n", i);
            return;  
        }
    }
    printf("Element not found!\n"); 
}

int main() {
    int test;
    printf("Enter the number of test cases: ");
    scanf("%d", &test);

    while (test--) {
        int n;
        printf("Enter the size of array: ");
        scanf("%d", &n);

        if (n <= 0) {
            printf("Invalid array size! Please enter a positive number.\n");
            continue;
        }

        int arr[n];
        printf("Enter the array elements: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int key;
        printf("Enter the key to be searched in array: ");
        scanf("%d", &key);

        linearsearch(arr, n, key);
    }
    return 0;
}
