//1
void dijkstra(int src,vector<pair<int,ll>> adj[],ll dist[],int n){
    fill(dist,dist+n+1,INF);
    dist[src]=0;
    set<pair<ll,int>> s;
    s.insert({0,src});
    int marked[n+1]={0};
    while (s.size()>0){
        int node=(*s.begin()).ss;
        ll d=(*s.begin()).ff;
        s.erase(s.begin());
        marked[node]=1;
        for (auto it:adj[node]){
            if (marked[it.ff]==1) continue;
            if (d+it.ss<dist[it.ff]){
                if (s.count({dist[it.ff],it.ff})>0) s.erase(s.find({dist[it.ff],it.ff}));
                dist[it.ff]=d+it.ss;
                s.insert({dist[it.ff],it.ff});
            }
        }
    }
}

//2
void dijkstra(int src,vector<pair<int,ll>> adj[],ll dist[],int n){
    fill(dist,dist+n+1,INF);
    dist[src]=0;
    set<pair<ll,int>> s;
    s.insert({0,src});
    while (s.size()>0){
        int node=(*s.begin()).ss;
        ll d=(*s.begin()).ff;
        s.erase(s.begin());
        if (d>dist[node]) continue;
        for (auto it:adj[node]){
            if (d+it.ss<dist[it.ff]){
                dist[it.ff]=d+it.ss;
                s.insert({dist[it.ff],it.ff});
            }
        }
    }
}
