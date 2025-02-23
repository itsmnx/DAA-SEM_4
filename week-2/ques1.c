#include <stdio.h>

// Function to find the first occurrence of key
int findFirst(int arr[], int low, int high, int key) {
    int first = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            first = mid;
            high = mid - 1;  // Move left
        } else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return first;
}

// Function to find the last occurrence of key
int findLast(int arr[], int low, int high, int key) {
    int last = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            last = mid;
            low = mid + 1;  // Move right
        } else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return last;
}

// Function to count occurrences of a key
int countOccurrences(int arr[], int n, int key) {
    int first = findFirst(arr, 0, n - 1, key);
    int last = findLast(arr, 0, n - 1, key);
    
    if (first == -1) {
        return 0;  // Key not found
    }
    return (last - first + 1);  // Count of occurrences
}

int main() {
    int test;
    
    printf("Enter the number of test cases: ");
    scanf("%d", &test);  // Read number of test cases

    while (test--) {
        int n;
        printf("\nEnter the size of array: ");
        scanf("%d", &n);  // Read array size

        int arr[n];
        printf("Enter the array elements in sorted order: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);  // Read sorted array elements
        }

        int key;
        printf("Enter the key to be searched: ");
        scanf("%d", &key);  // Read the key to search

        int count = countOccurrences(arr, n, key);
        if (count > 0) {
            printf("%d %d\n", key, count);  // Output in required format
        } else {
            printf("Key not present\n");  // If key is not found
        }
    }

    return 0;
}

 
