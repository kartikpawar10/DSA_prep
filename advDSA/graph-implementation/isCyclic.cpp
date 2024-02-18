#include<iostream>
using namespace std;

   bool solve(int i,unordered_map<int,bool>&vis,vector<int> adj[]){
        unordered_map<int,int>parent;
        parent[i] = -1;
        vis[i] = true;
        queue<int>q;
        q.push(i);
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto it:adj[front]){
                if(vis[it] && it != parent[front]){
                    return true;
                }else if(!vis[it]){
                    q.push(it);
                    vis[it] = true;
                    parent[it] = front;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool>vis;
        bool ans = false;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                ans = solve(i,vis,adj);
                if(ans == true){
                    break;
                }
            }
        }
        return ans;
    }

int main(){
	return 0;
}