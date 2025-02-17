

#include<stdio.h>

int binarysearch(int arr[], int low, int high, int key) {
    int count = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (arr[mid] == key) {
          
            int temp = mid;
            while (temp >= low && arr[temp] == key) {
                count++;
                temp--;
            }
            temp = mid + 1;
            while (temp <= high && arr[temp] == key) {
                count++;
                temp++;
            }
            
            return count;  
        } else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return 0; 
}

int main() {
    int test;
    printf("Enter the number of test cases: ");
    scanf("%d", &test);
    
    while (test--) {
        int n;
        printf("Enter the size of array: ");
        scanf("%d", &n);
        
        int arr[n];
        printf("Enter the array elements in sorted order: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        int key;
        printf("Enter the key to be searched in array: ");
        scanf("%d", &key);
        
        printf("Duplication occurs %d times for key %d\n", binarysearch(arr, 0, n - 1, key), key);
    }
    
    return 0;
}
