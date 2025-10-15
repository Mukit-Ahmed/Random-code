void dfs(vector<int> &components,int node,vector<bool> &visited,vector<vector<int>> &adj){

components.push_back(node);
visited[node]=1;
for(auto i:adj[node] ){
    if(!visited[i]){
        dfs(components,i,visited,adj);
    }
}

}


vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
vector<vector<int>> adj(V);
for(int i = 0 ;i<E;i++){
    adj[edges[i][0]].push_back(edges[i][1]);
    adj[edges[i][1]].push_back(edges[i][0]);
}

vector<bool> visited(V,0);
vector<vector<int>> ans;
for(int i=0;i<V;i++){
vector<int> components;
if(!visited[i]){
 dfs(components,i,visited,adj);
 ans.push_back(components);
}

}

    return ans;

}
// https://www.naukri.com/code360/problems/dfs-traversal_630462?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
