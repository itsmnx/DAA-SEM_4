#include<bits/stdc++.h>
using namespace std;


vector<int> findElements(vector<int>& arr) {
    int n = arr.size();
    if (n < 3) return {};  
    vector<int> leftMax(n), rightMin(n), result;

  
    leftMax[0] = arr[0];
    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i - 1], arr[i - 1]);

  
    rightMin[n - 1] = arr[n - 1];  
    for (int i = n - 2; i >= 0; i--)
        rightMin[i] = min(rightMin[i + 1], arr[i + 1]);

   
    for (int i = 1; i < n - 1; i++) {
        if (leftMax[i] < arr[i] && arr[i] < rightMin[i]) 
            result.push_back(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 3, 5, 10, 9, 12};
    vector<int> result = findElements(arr);
    
    cout << "Valid elements: ";
    for (int num : result) 
        cout << num << " ";
    
    return 0;
}
