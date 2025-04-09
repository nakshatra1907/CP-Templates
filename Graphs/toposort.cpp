//Valid for DAG

//1 DFS(multisource) Method 
void dfs(int node,vector<int> &vis,vector<int> adj[],stack<int> &st){
    vis[node]=1;
    for (auto it:adj[node]){
        if (vis[i]==1) continue;
    }
    st.push(node);
}
//(Stack contains reverse order)

//2 BFS(multisource) Method (Kahn's Algorithm)
void kahn(int node,vector<int> &vis,vector<int> &indegvector<int> &indeg,vector<int> adj[],vector<int> &topo){
    queue<int> q;
    q.push(node);
    vis[node]=1;
    while (q.size()>0){
        int x=q.front();
        q.pop();
        topo.pb(x);
        for (auto it:adj[node]){
            indeg[it]--;
            if (vis[node]==0 && indeg[it]==0){
                q.push(it);
                vis[it]=1;
            }
        }
    }
}
//nodes passed are of indegree 0 and unvisited
