#include<iostream>
#include<queue>
using namespace std;

int getKthLargest(vector<int>&arr,int k){
	priority_queue<int,vector<int>,greater<int>>change;
	int n = arr.size();
	for(int i=0;i<n;i++){
		int sum = 0;
		for(int j = i;j<n;j++){
			sum+=arr[j];
			if(change.size() < k){
				change.push(sum);
			}else{
				if(sum>change.top()){
					change.pop();
					change.push(sum);
				}
			}
		}
	}
	return change.top();
}

int main(){
	return 0;
}