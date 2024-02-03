#include<iostream>
#include<queue>
using namespace std;

// Minimum Cost of Ropes

long long minCost(long long arr[],long long n){
	priority_queue<long long,vector<long long>,greater<long long>>pq;
	for(int i=0;i<n;i++){
		pq.push(arr[i]);
	}
	long long a = 0;
	long long b = 0;
	long long = 0;
	long long cost = 0;
	while(pq.size() > 1){
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();

		sum = a + b;
		cost+=sum;
		pq.push(sum);
	}
	return pq.top();
}