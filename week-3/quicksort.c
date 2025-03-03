#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform partition and return the pivot index
int partition(int *arr, int low, int high) {
    int pivot = arr[high];  // Use the last element as the pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to check for duplicates in the sorted array
int hasDuplicates(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {  // If two consecutive elements are the same
            return 1;  // Duplicates found
        }
    }
    return 0;  // No duplicates
}

int main() {
    int T, n;

    // Ask user for the number of test cases
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    while (T--) {
        // Ask user for the size of the array
        printf("Enter the size of the array: ");
        scanf("%d", &n);

        int *arr = (int*)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        // Ask user to input the elements of the array
        printf("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        // Sort the array using quickSort
        quickSort(arr, 0, n - 1);

        // Check for duplicates
        if (hasDuplicates(arr, n)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

        // Free dynamically allocated memory
        free(arr);
    }

    return 0;
}
