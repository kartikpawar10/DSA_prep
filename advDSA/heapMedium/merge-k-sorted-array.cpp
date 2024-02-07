#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 

// creating node to track multiple data for a specific address

class node{
public:
	int data;
	int i;
	int j;
	node(int d,int row,int col){
		this->data = d;
		this->i = row;
		this->j = col;
	}
};

// comapared for the given node given above
class compare{
public:
	bool operator()(node* a,node* b){
		return a->data > b->data;
	}
};

vector<int> mergeKsortedArray(vector<vector<int>>&kArrays,int k){

	// inserting minHeap for all element in the for the first index;

	priority_queue<node*,vector<node*>,compare>minHeap;
	for(int i=0;i<=k;i++){
		node* temp = new node(kArrays[i][0],i,0);
		minHeap.push(temp);
	}

	// ans for returning

	vector<int>ans;

// running this while loop until the mniHeap gets empty

	while(!minHeap.empty()){

		// all things are inserted in the minHeap for checking the thing will get out of the range

		node* temp = minHeap.top();
		ans.push_back(temp->data);
		int i = temp->i;
		int j = temp->j;

		// putting the next element in the heap
		if(j+1<kArrays[i].size()){
			node* next = new node(kArrays[i][j],i,j);
			minHeap.push(next);
		}
	}
	return ans;
}


int main(){

}