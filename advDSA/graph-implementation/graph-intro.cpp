#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class Graph{

public:
	unordered_map<int,list<int>>adj;

	void addEdge(int u,int v,bool dir){

		// dir == 0 for directed or vice versa;
		adj[u].push_back(v);

		if(!dir){
			adj[v].push_back(u);
		}
	}

	void printAdjList(){
		for(auto i:adj){
			cout<<i.first<<" -> ";
			for(auto j:i.second){
				cout<<j<<",";
			}
			cout<<endl;
		}
	}

};

int main(){
	int n , m;
	cout<<"Enter the Number of node:: ";
	cin>>n;
	cout<<"Enter the Number of edges:: ";
	cin>>m;
	Graph g;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g.addEdge(u,v,0);
	}
	g.printAdjList();
	return 0;
}