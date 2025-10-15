vector<int> bfsTraversal(int n, vector<vector<int>> &adj)
{
    vector<int>ans;
    vector<bool>visited(n,false);

    deque<int> dq;
    dq.push_back(0);

    visited[0]=1;

    while(!dq.empty())
    {
        int frontnode=dq.front();
        dq.pop_front();
        ans.push_back(frontnode);
        for(int i:adj[frontnode])
        {
            if(!visited[i])
            {
                dq.push_back(i);
                visited[i] = 1;
            }
        }
    }
    return ans;
}
// https://www.naukri.com/code360/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
