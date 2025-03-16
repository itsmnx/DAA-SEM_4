
//linear search in O(n)
#include<bits/stdc++.h>
using namespace std;

/*int countones(const vector<int>&arr){
    int count=0;
    for(int num:arr){
        if(num==1) count++;
        else break;
    }
    return count;
}

int main(){
    vector<int>arr={1,1,1,1,1,0,0};
    cout<<countones(arr);
    return 0;

}*/
int countones(vector<int>&arr){
    int n=arr.size();
    int ans=0,low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==0){
            high=mid-1;
        }
        else if(mid==n-1||arr[mid+1]!=1){
            return mid+1;
        }
        else{
            low=mid+1;
        }
    }
    return 0;   
}
int main(){
    vector<int>arr={1,1,1,1,1,0,0};
    cout<<countones(arr);
    return 0;
}
