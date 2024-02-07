#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int kthsmallestsumsubarray(int arr[],int n,int k){

	priority_queue<int,vector<int>,greater<int>>pq;
	int sum  = 0;
	for(int i=0;i<n;i++){
		sum = 0;
			for(int j=i;j<n;j++){
			sum+=arr[j];
			if(pq.size() <= k){
				pq.push(sum);
			}else{
				if(pq.top() < sum){
					pq.pop();
					pq.push(sum);
				}
			}
		}
	}
	return pq.top();
}

int main(){
	int arr[5] = {1,2,6,4,3};
	cout<<kthsmallestsumsubarray(arr,5,1)<<endl;
	return 0;
}