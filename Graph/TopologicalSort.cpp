#include<unordered_map>
#include<list>
#include<queue>
#include <string>
#include<stack>
#include<vector>
#include<iostream>
using namespace std;

//valid only for directed acyclic graph  NOT for cyclic graphs !!
//Using DFS , in this we put the node in stack whenever recursion call returns

//T.C -> linear O(node + edges)
//S.c -> linear


//using dfs
void topoSort(int node,unordered_map<int,bool> &visited,stack<int> &s 
,unordered_map<int,list<int>> &adj){
    visited[node] = true;

    for(auto neighbour:adj[node]){
        if(!visited[neighbour]){
            topoSort(neighbour,visited,s,adj);
        }
    }
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<int> indegree(v);
    for(auto i:adj){
        for(auto j:i.second){    //i is the pair of node and its list so i.second represents list of that node
            indegree[j]++;
        }
    }

   //0 indegree waalo ko push krdo
   queue<int> q;
   for(int i=0;i<v;i++){
    if(indegree[i] == 0){
        q.push(i);
    }

    //do bfs
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        ans.push_back(front);
        for(auto i:adj[front]){
            indegree[i]--;
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }
   }
   return ans;
}


