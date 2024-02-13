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
    void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>>&adj,vector<int>&matter){
    	component.push_back(node);
    	visited[node] = true;
    	for(auto i:adj[node]){
    		if(!visited[i]){
    			dfs(i,visited,adj,component);
    		}
    	}
    }
    vector<vector<int>>dfs(int V,int E,vector<vector<int>>edges){
    	// first create an adjancency list
    	unordered_map<int,list<int>>adj;
    	for(int i=0;i<edges.size();i++){
    		int u = edges[i][0];
    		int v = edges[i][1];
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	vector<vector<int>>ans;
    	unordered_map<int,bool>visited;

    	// for all nodes
    	for(int i=0;i<V;i++){
    		if(!visited){
    			vector<int>matter;
    			dfs(i,visited,adj,matter);
    			ans.push_back(component);
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
	ans = g.bfsOfGraph(1,ans);
	for(auto it:ans){
		cout<<it<<" ";
	}cout<<endl;

	return 0;
}