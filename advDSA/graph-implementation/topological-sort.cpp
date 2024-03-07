/*topological-sort.cpp
Directed Acyclic Graph (DAG)
what - Liner Ordering of vertices such that for every edge 
u->v edge, u always appers before v is that ordering

    0      0 1 3 2  (Valid) 3 2 1 0 (Invalid)
   / \     0 -> 1 ,3 
  1   3    1 -> 2
   \ /     2 ->
    2      3 -> 2

    Using DFS
*/

#include<iostream>
#include<unordered_map>
#include<list>
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void solve(int node,unordered_map<int,bool>&vis,stack<int>&s,vector<int> adj[]){
	    vis[node] = 1;
	    
	    for(auto neighbour : adj[node]){
	        if(!vis[neighbour]){
	            solve(neighbour,vis,s,adj);
	        }
	    }
	    s.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    unordered_map<int,bool>vis;
	    stack<int>s;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            solve(i,vis,s,adj);
	        }
	    }
	    vector<int>ans;
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};
