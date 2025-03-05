#include <stdio.h>

void merge(int arr[], int left, int mid, int right, int *comparisons, int *inversions) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            (*inversions) += (n1 - i); // Count inversions
        }
    }
    
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right, int *comparisons, int *inversions) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, comparisons, inversions);
        mergeSort(arr, mid + 1, right, comparisons, inversions);
        merge(arr, left, mid, right, comparisons, inversions);
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
        
        int comparisons = 0, inversions = 0;
        mergeSort(arr, 0, n - 1, &comparisons, &inversions);
        
        printf("Sorted array: ");
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\nComparisons = %d", comparisons);
        printf("\nInversions = %d\n", inversions);
    }
    return 0;
}
