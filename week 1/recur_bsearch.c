#include<stdio.h>
void binarysearch(int arr[],int low,int high,int key){

   if(low>high){
    printf("Element not found in array!\n");
    return;
   }
   int mid=(low+high)/2;
   if(arr[mid]==key){
    printf("Element found at index %d\n",mid);
    return;
   }
   if(arr[mid]<key){
   binarysearch(arr,mid+1,high,key);
   }
   else{
   binarysearch(arr,low,mid-1,key);
   }
   
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
        binarysearch(arr, 0,n-1,key);
    }
    return 0;
}
