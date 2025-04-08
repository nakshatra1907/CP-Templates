void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> edges;
    for (int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.pb({w,{u,v}});
    }
    sort(edges.begin(),edges.end());
    dsu d(n);
    int sum=0;
    for (auto it:edges){
        int w=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if (d.findpar(u)!=d.findpar(v)){
            sum+=w;
            d.unionsize(u,v);
            cout<<u<<" "<<v<<" "<<w<<endl;
        }
    }
    cout<<sum<<endl;
}
