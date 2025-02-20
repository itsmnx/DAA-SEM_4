#include<stdio.h>
void triplets(int arr[], int n) {
    int found = 0;
    for (int k = 2; k < n; k++) {
        int i = 0, j = k - 1;
        while (i < j) {
            int sum = arr[i] + arr[j];
            if (sum == arr[k]) {
                printf("arr[%d] +arr[%d] =arr[%d]\n",i,j,k);
                found++;
                i++;
                j--;
            }
            else if (sum < arr[k]) {
                i++;
            }
            else {
                j--;
            }
        }
    }

    if (!found) {
        printf("No such indices found in the array!!\n");
    }
}
int main() {
    int test;
    printf("Enter the number of test cases: ");
    scanf("%d", &test);
    
    while (test--) {
        int n;
        printf("Enter the array size: ");
        scanf("%d", &n);
        int arr[n];
        
        printf("Enter array elements: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        triplets(arr, n);
    }
    
    return 0;
}

