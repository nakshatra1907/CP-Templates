
void dfs(int node,vector<int> &vis,vector<int> adj[],stack<int> &st){
    vis[node]=1;
    for (auto it:adj[node]){
        if (vis[it]==1) continue;
        dfs(it,vis,adj,st);
    }
    st.push(node);
}

void dfs2(int node,vector<int> &vis,vector<int> adj[],vector<int> &temp){
    vis[node]=1;
    temp.pb(node);
    for (auto it:adj[node]){
        if (vis[it]==1) continue;
        dfs2(it,vis,adj,temp);
    }
}


void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1],tadj[n+1];
    for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        tadj[v].pb(u);
    }
    vector<int> vis(n+1,0);
    stack<int> st;
    for (int i=1;i<=n;i++){
        if (vis[i]==0) dfs(i,vis,adj,st);
    }
    vector<vector<int>> scc;
    vector<int> temp;
    fill(vis.begin(),vis.end(),0);
    while (st.size()>0){
        int top=st.top();
        st.pop();
        if (vis[top]==0){
            dfs2(top,vis,tadj,temp);
            scc.pb(temp);
            temp.clear();
        }
    }
    cout<<scc.size()<<endl;
    for (auto it:scc){
        for (auto j:it){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
