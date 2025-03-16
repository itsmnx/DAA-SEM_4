#include <bits/stdc++.h>
using namespace std;

vector<char> countSort(vector<char>& arr) {
    int n = arr.size();
    if (n == 0) return {};

    char k = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > k) {
            k = arr[i];
        }
    }

    vector<int> count(k + 1, 0);
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= k; i++) {
        count[i] += count[i - 1];
    }

    vector<char> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }

    return output;
}

void findMaxOccurrence(vector<char>& sortedArr) {
    int n = sortedArr.size();
    if (n == 0) return;

    int maxFreq = 1, currFreq = 1;
    char maxElement = sortedArr[0];

    for (int i = 1; i < n; i++) {
        if (sortedArr[i] == sortedArr[i - 1]) {
            currFreq++;
        } else {
            currFreq = 1;
        }

        if (currFreq > maxFreq) {
            maxFreq = currFreq;
            maxElement = sortedArr[i];
        }
    }

    if (maxFreq == 1) {
        cout << "No Duplicates Present" << endl;
    } else {
        cout << maxElement << " " << maxFreq << endl;
    }
}

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    while (T--) {
        int n;
        cout << "Enter the size of the array: ";
        cin >> n;

        vector<char> arr(n);
        cout << "Enter the array elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<char> sortedArr = countSort(arr);
        findMaxOccurrence(sortedArr);
    }

    return 0;
}


/*#include<bits/stdc++.h>
using namespace std;

void countsort(int arr[],int n){
    int k=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>k){
        k=arr[i];}
    }
    vector<int>count(k+1,0);

    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<=k;i++){//prefix sum
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--count[arr[i]]]=arr[i];
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}
int main(){
    int test;
    cout<<"Enter the test cases: "<<endl;
    cin>>test;
    while(test--){
        int n;
        cout<<"Enter the size : "<<endl;
        cin>>n;
        int arr[n];
        cout<<"Enter the array elements : "<<endl;
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        countsort(arr,n);
        cout<<"Soterd array is:";
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;

void countsort(int arr[], int n) {  // Changed return type to void
    // Find the maximum element
    int k = 0;  // Initialize to 0, not arr[0] (which can be problematic if array is empty)
    for(int i = 0; i < n; i++) {
        k = max(k, arr[i]);
    }
    
    // Create count array with size k+1 (not fixed size 10)
    vector<int> count(k + 1, 0);  // Using vector for dynamic sizing
    
    // Count occurrences
    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    // Update count with cumulative sum
    for(int i = 1; i <= k; i++) {
        count[i] += count[i-1];
    }
    
    // Create output array
    vector<int> output(n);
    
    // Build the output array
    for(int i = n-1; i >= 0; i--) {
        output[--count[arr[i]]] = arr[i];
    }
    
    // Copy output back to original array
    for(int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    int test;
    cout << "Enter the test cases: " << endl;
    cin >> test;
    
    while(test--) {
        int n;
        cout << "Enter the size: " << endl;
        cin >> n;
        
        int arr[n];
        cout << "Enter the array elements: " << endl;
        // Corrected input loop
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        countsort(arr, n);  // No need to capture return value
        
        cout << "Sorted array is: ";
        // Corrected output loop
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}*/
