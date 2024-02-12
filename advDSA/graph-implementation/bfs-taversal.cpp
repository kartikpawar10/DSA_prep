#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>
using namespace std;


class graph{
	public:
		unordered_map<int,list<int>>adj;

	void addEdge(int u,int v,bool dir){
		adj[u].push_back(v);
		if(!dir){
			adj[v].push_back(u);
		}
	}
	void printAdjList(){
		for(auto i:adj){
			cout<<i.first<<"-> ";
			for(auto j:i.second){
				cout<<j<<",";
			}
		}
		cout<<endl;
	}

		vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int>ans;
        ans.push_back(0);
        queue<pair<int,vector<int>>>q;
		unordered_map<int,bool>vis;
        vis[0] = true;
		int source = 0;
		q.push(make_pair(source,adj[source]));
		while(!q.empty()){
			auto el = q.front();
			q.pop();
			for(auto it:el.second){
				if(!vis[it]){
					q.push((make_pair(it,adj[it])));
					ans.push_back(it);
					vis[it] = true;
				}
			}
		}
		return ans;
    }
};

int main(){

	graph g;
	vector<int>ans;
	int n , m;
	cout<<"Enter Number of Nodes : ";cin>>n;
	cout<<"Enter Number of Edges : ";cin>>m;

	for(int i=0;i<m;i++){
		int u , v;
		cin>>u>>v;
		g.addEdge(u,v,0);
	}
	g.printAdjList();
	g.bfsTraversal(1,ans);
	for(auto it:ans){
		cout<<it<<" ";
	}cout<<endl;

	return 0;
}