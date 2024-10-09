#include<iostream>
#include<list>
#include<vector>


void dfs(int node, unordered_map<int,bool> &visited, 
unordered_map<int,list<int>> &adj, vector<int> &Component){
    Component.push_back(node);
    visited[node] = true;

    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,visited,adj,Component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{   //prepare adjancy List
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int,bool> visited;

    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> Component;
            dfs(i,visited,adj,Component);
            ans.push_back(Component);
        }
    }
    return ans;
}
