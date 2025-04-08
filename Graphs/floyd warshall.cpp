void floyd(vector<pair<int,int>> adj[]){
    int n,m;
    cin>>n>>m;
    ll cost[n+1][n+1];
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++){
            if (i==j) cost[i][j]=0;
            else cost[i][j]=INF;
        }
    }
    for (int i=0;i<m;i++){
        int u,v;
        ll w;
        cin>>u>>v>>w;
        cost[u][v]=min(cost[u][v],w);
    }
    for (int via=1;via<=n;via++){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if (cost[i][via]==INF || cost[via][j]==INF) continue;
                cost[i][j]=min(cost[i][j],cost[i][via]+cost[via][j]);
            }
        }
    }
    // if cost[i][i]<0 for any i then negative cycle exists
    //tc----> O(n**3)
}
