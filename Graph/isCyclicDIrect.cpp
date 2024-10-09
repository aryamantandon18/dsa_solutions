#include<unordered_map>
#include<list>
#include<queue>
#include <string>
#include<vector>
#include<iostream>
using namespace std;

//cyclic condition -> is visited and is dfsVisited also


bool isCycleDFS(int node, unordered_map<int, bool> &visited,
                unordered_map<int, bool> &dfsVisited,
                unordered_map<int, list<int>> &adj) {
  visited[node] = true;
  dfsVisited[node] = true;

  for (auto neighbour : adj[node]) {
    if (!visited[neighbour]) {
      bool cyclePresent = isCycleDFS(neighbour, visited, dfsVisited, adj);
      if (cyclePresent) {
        return true;
      } else if (dfsVisited[neighbour]) {
        return true;
      }
    }
  }
  dfsVisited[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
  // creating adjancy list
  unordered_map<int, list<int>> adj;
  for (int i = 0; i < edges.size(); i++) {
    int u = edges[i].first;
    int v = edges[i].second;

    adj[u].push_back(v);
  }

  unordered_map<int, bool> visited;
  unordered_map<int, bool> dfsVisited;

  // call dfs for all components
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      bool cycleFound = isCycleDFS(i, visited, dfsVisited, adj);
      if (cycleFound) {
        return 1;
      }
    }
  }
  return 0;
}