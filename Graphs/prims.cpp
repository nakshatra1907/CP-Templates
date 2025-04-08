void prims(vector<pair<int,int>> adj[]){
    priority_queue<vector<ll>> pq;
    vector<int> vis(n+1,0);
    ll sum=0;
    vector<pair<int,int>> edges;
    pq.push({0,1,0}); // {-wt,node,par}
    while (pq.empty()==false){
        int node=pq.top()[1];
        ll wt=-pq.top()[0];
        int par=pq.top()[2];
        pq.pop();
        if (vis[node]==1) continue;
        vis[node]=1;
        sum+=wt;
        if (par!=0) edges.pb({node,par});
        for (auto it:adj[node]){
            if (vis[it.first]==1) continue;
            pq.push({-it.second,it.first,node});
        }
    }
}
