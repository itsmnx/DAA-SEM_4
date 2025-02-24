#include<stdio.h>
void insertionsort(int arr[],int n){

for(int i=1;i<n-1;i++){
int temp=arr[i];
int j=i-1;
shift++;
while(j>=0&&arr[j]>temp){
count++;
arr[j+1]=arr[j];
shift++;
j--;
}
arr[j+1]=temp;
shift++;
}
}

void print(int arr[],int n){
for(int i=0;i<n;i++){
printf("%

int main() {
    int test;
    printf("Enter the number of test cases: ");
    scanf("%d", &test);
    while (test--) {
        int n;
        printf("\nEnter the size of array: ");
        scanf("%d", &n)
        int arr[n];
        printf("Enter the array elements in sorted order: ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);  
        }
        int count=0;
	int shift=0;
        insertionsort(arr,n,count,shift);
    }
    return 0;
}
