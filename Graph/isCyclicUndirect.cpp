#include<unordered_map>
#include<list>
#include<queue>
#include <string>
#include<vector>
#include<iostream>
using namespace std;

//ignoring neighbour if it is visited and is parent of frontNode (node)
// it is answer (true) if visited but not parent 
bool isCyclicBFS(int src,unordered_map<int,bool> &visited,
unordered_map<int,list<int>> &adj){
    unordered_map<int,int> parent;
    parent[src] = -1;
    visited[src] = 1;
    
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto neighbour:adj[front]){
            if(visited[neighbour] == 1 && neighbour != parent[front] ){
                return true;  //cycle present 
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
                }
        }
    }
    return false;
}

bool isCyclicDFS(int node,int parent,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj){
    visited[node] = true;
    for(auto i:adj[node]){
        if(!visited[i]){
            isCyclicDFS(i,node,visited,adj);
        }
        else if(i != parent){
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>> adj;
    
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            //bool ans = isCyclicDFS(i,-1,visited,adj);
            bool ans = isCyclicBFS(i,visited,adj);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    return "No";
}


int main() {
    int n, m;
    cout << "Enter the number of vertices (n): ";
    cin >> n;

    cout << "Enter the number of edges (m): ";
    cin >> m;

    vector<vector<int>> edges(m, vector<int>(2));

    cout << "Enter the edges (format: u v):\n";
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1];
    }

    string result = cycleDetection(edges, n, m);

   cout << "Cycle present? " << result << endl;

    return 0;
}