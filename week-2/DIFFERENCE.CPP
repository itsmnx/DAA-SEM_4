#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int countpairs(vector<int>&arr,int k){
	sort(arr.begin(),arr.end());
	int count=0,i=0,j=i+1;
	while(j<arr.size()){
		int diff=arr[j]-arr[i];
		if(diff==k){
		count++;
		i++;
		j++;
		}else if(diff<k){
		j++;
		}else{
		i++;
		}
		if(i==j){
		j++;}
	}
	return count;
}

int main(){
	int test;
	cout<<"Enter the number of test cases: ";
	cin>>test;
	while(test--){
	int n;
	cout<<"Enter the size of array: ";
	cin>>n;
	vector<int>arr(n);
	cout<<"Enter the array elements: ";
	for(int i=0;i<n;i++){
	cin>>arr[i];
	}
	int k;
	cout<<"enter the key k: ";
	cin>>k;
	int res=countpairs(arr,k);
	cout<<"Number of pairs with difference "<<k<<":"<<res<<endl;
	}
return 0;
}
