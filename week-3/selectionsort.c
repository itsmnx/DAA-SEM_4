#include <stdio.h>
#include <stdlib.h> 

// Function to perform selection sort and count comparisons and swaps
void selectionSort(int *arr, int n, int *comparisons, int *swaps) {
    int i, j, minIndex, temp;

    // Loop through all elements of the array
    for (i = 0; i < n - 1; i++) {
        minIndex = i;

        // Find the minimum element in the unsorted part
        for (j = i + 1; j < n; j++) {
            (*comparisons)++;  // Increment comparison count
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element
        if (minIndex != i) {
            (*swaps)++;  // Increment swap count
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int T, n, i;
    
    // Prompt user for number of test cases
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    while (T--) {
        // Prompt user for the size of the array
        printf("\nEnter the number of elements in the array: ");
        scanf("%d", &n);

        // Dynamically allocate memory for the array
        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;  // Exit if memory allocation fails
        }

        int comparisons = 0, swaps = 0;

        // Prompt user to enter the elements of the array
        printf("Enter the elements of the array: ");
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        // Perform selection sort
        selectionSort(arr, n, &comparisons, &swaps);

        // Output the sorted array
        printf("\nSorted array: ");
        for (i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // Output the number of comparisons and swaps
        printf("Comparisons: %d\n", comparisons);
        printf("Swaps: %d\n", swaps);

        // Free the dynamically allocated memory
        free(arr);
    }

    return 0;
}
