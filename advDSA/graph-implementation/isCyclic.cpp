#include<iostream>
using namespace std;

bool isCyclic(int src,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj,unordered_map<int,int>parent){
	parent[src] = -1;
	visited[src] = 1;
	queue<int>q;
	q.push(src);
	while(!q.empty()){
		int front = q.front();
		q.pop();
// simple si baat h ki visited ho gya pr wo current level ka parent nhi aise kese
		for(auto it: adj[front]){
			if(visited[it] == true && it != parent[front]){
				return false;
			}else if(!visited[it]){
				visited[it] = true;
				parent[it] = front;
				q.push(it);
			}
		}
	}
	return false;
}

int main(){
	return 0;
}