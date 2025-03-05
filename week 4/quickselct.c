#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);
        if (pivotIndex == k)
            return arr[pivotIndex];
        else if (pivotIndex < k)
            return quickSelect(arr, pivotIndex + 1, high, k);
        else
            return quickSelect(arr, low, pivotIndex - 1, k);
    }
    return -1;
}

int main() {
    int T;
    printf("Enter number of test cases: ");
    scanf("%d", &T);
    
    while (T--) {
        int n, k;
        printf("Enter size of array: ");
        scanf("%d", &n);
        
        int *arr = (int*)malloc(n * sizeof(int));
        printf("Enter %d elements: ", n);
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        
        printf("Enter the value of k: ");
        scanf("%d", &k);
        
        if (k < 1 || k > n) {
            printf("not present\n");
        } else {
            int result = quickSelect(arr, 0, n - 1, n - k);
            printf("%d\n", result);
        }
        
        free(arr);
    }
    
    return 0;
}
