
 #include<iostream>
 #include<priority_queue>


 
 int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> mst(V, 0); //like visited
    // vector<int> parent(V,-1);

    // lets start the algo 
    pq.push({0, 0});
    int sum = 0;

    while (!pq.empty())
    {
        pair<int, int> it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;

        if (mst[node] == 1)
            continue;
        // mark minNode as true
        mst[node] = 1; // fix: should be 1, not 0
        sum += wt;

        for (auto i : adj[node])
        {
            int adjnode = i[0];
            int w = i[1];
            if (!mst[adjnode])
            {
                pq.push({w,adjnode});
            }
        }
    }
    return sum;
}