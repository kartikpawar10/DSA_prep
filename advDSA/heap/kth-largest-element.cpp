#include<bits/stdc++.h>
using namespace std;

int kthsmallestElement(int arr[],int r,int k){
	priority_queue<int,vector<int>,greater<int>>minHeap;
	for(int i=0;i<k;i++){
		minHeap.push(arr[i]);
	}
	for(int i=k;i<=r;i++){
		if(arr[i] > minHeap.top()){
			minHeap.pop();
			minHeap.push(arr[i]);
		}
	}

	return minHeap.top();
}

int main(){

	int arr[5] = {5,65,34,23,54};
	int k = 3;
	int r = 4;
	cout<<"kth largest element is :: "<<kthsmallestElement(arr,4,3)<<endl;
	return 0;
}
