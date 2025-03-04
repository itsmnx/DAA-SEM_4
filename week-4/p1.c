#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void merge(int *arr, int *temp, int left, int mid, int right, long *comparisons, long *inversions) {
    int i = left;    
    int j = mid + 1; 
    int k = left;    
    while (i <= mid && j <= right) {
        (*comparisons)++;
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int *arr, int *temp, int left, int right, long *comparisons, long *inversions) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, temp, left, mid, comparisons, inversions);      
        mergeSort(arr, temp, mid + 1, right, comparisons, inversions); 
        merge(arr, temp, left, mid, right, comparisons, inversions);   
    }
}

int main() {
    int T, n;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);
    while (T--){
        printf("Enter the size of the array: ");
        scanf("%d", &n);
        int *arr = (int*)malloc(n * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        printf("Enter the elements of the array: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        int *temp = (int*)malloc(n * sizeof(int));
        if (temp == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        long comparisons = 0,long inversions = 0;  
        mergeSort(arr, temp, 0, n - 1, &comparisons, &inversions);
        printf("Comparisons: %ld\n", comparisons);
        printf("Inversions: %ld\n", inversions);
        free(arr);
        free(temp);
    }

    return 0;
}
