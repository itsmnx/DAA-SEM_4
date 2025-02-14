#include<stdio.h>
void binarysearch(int arr[],int n,int key){
    int low=0;
    int high=n-1;
    while(low<=high){
    int mid=(low+high)/2;
    if(arr[mid]==key){
        printf("Element found at index %d",mid);
        return;
    }
    else if(arr[mid]<key){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
    }
    printf("Element not found!\n");

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
        binarysearch(arr, n, key);
    }
    return 0;
}
