#include <stdio.h>

void findCommonElements(int arr1[], int m, int arr2[], int n) {
    int i = 0, j = 0, prev = -1, found = 0;

    printf("Common elements: ");
    
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            i++;
        } 
        else if (arr1[i] > arr2[j]) {
            j++;
        } 
        else {
            if (arr1[i] != prev) {
                printf("%d ", arr1[i]);
                prev = arr1[i];
                found = 1;
            }
            i++;
            j++;
        }
    }

    if (!found) {
        printf("No common elements found.");
    }
    printf("\n");
}

int main() {
    int T;
    printf("Enter number of test cases: ");
    scanf("%d", &T);

    while (T--) {
        int m, n;
        printf("Enter size of first array: ");
        scanf("%d", &m);
        int arr1[m];
        printf("Enter elements of first sorted array: ");
        for (int i = 0; i < m; i++) {
            scanf("%d", &arr1[i]);
        }

        printf("Enter size of second array: ");
        scanf("%d", &n);
        int arr2[n];
        printf("Enter elements of second sorted array: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr2[i]);
        }

        findCommonElements(arr1, m, arr2, n);
    }

    return 0;
}
