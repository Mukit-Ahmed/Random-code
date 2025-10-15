vector<int> shortestPath( vector<pair<int,int>> edges, int n, int m, int s, int t)
{

    vector<vector<int>> adj(n+1);
    for(int i = 0; i<edges.size(); i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    vector<bool> visited(n+1,0);
    queue<int> q;
    q.push(s);
    visited[s]=1;
    vector<int> parent(n+1,-1);

    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        for(auto i :adj[front])
        {
            if(!visited[i])
            {
                parent[i]=front;
                visited[i]=1;
                q.push(i);
            }
        }
    }

    vector<int> ans;
    int p = t;
    while(p != -1)
    {
        ans.push_back(p);
        if(p == s) break;
        p = parent[p];
    }
    reverse(ans.begin(),ans.end());
    return ans;

}
