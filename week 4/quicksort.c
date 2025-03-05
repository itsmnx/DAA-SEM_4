#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b, int *swaps) {
    int temp = *a;
    *a = *b;
    *b = temp;
    (*swaps)++;
}

int partition(int arr[], int low, int high, int *comparisons, int *swaps) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        (*comparisons)++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j], swaps);
        }
    }
    swap(&arr[i + 1], &arr[high], swaps);
    return i + 1;
}

void quickSort(int arr[], int low, int high, int *comparisons, int *swaps) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, swaps);
        quickSort(arr, low, pi - 1, comparisons, swaps);
        quickSort(arr, pi + 1, high, comparisons, swaps);
    }
}

int main() {
    int T;
    printf("Enter number of test cases: ");
    scanf("%d", &T);
    while (T--) {
        int n;
        printf("Enter size of array: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter %d elements: ", n);
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        
        int comparisons = 0, swaps = 0;
        quickSort(arr, 0, n - 1, &comparisons, &swaps);
        
        printf("Sorted array: ");
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\nComparisons = %d", comparisons);
        printf("\nSwaps = %d\n", swaps);
    }
    return 0;
}
