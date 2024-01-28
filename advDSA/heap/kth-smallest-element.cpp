#include<bits/stdc++.h>
using namespace std;

int kthsmallestElement(int arr[],int r,int k){
	priority_queue<int>maxheap;
	for(int i=0;i<k;i++){
		maxheap.push(arr[i]);
	}
	for(int i=k;i<=r;i++){
		if(arr[i] < maxheap.top()){
			maxheap.pop();
			maxheap.push(arr[i]);
		}
	}

	return maxheap.top();
}

int main(){

	int arr[5] = {5,65,34,23,54};
	int k = 3;
	int r = 4;
	cout<<"kth smallest element is :: "<<kthsmallestElement(arr,4,5)<<endl;
	return 0;
}
