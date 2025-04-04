#include <bits/stdc++.h>
using namespace std;
#define pb push_back

class dsu{
    vector<int> parent,size,rank;

public:
    dsu(int n){
        for (int i=0,i<=n;i++){
            parent.pb(i);
            size.pb(1);
            rank.pb(0);
        }
    }
    
    int findpar(int node){
        if (parent[node]==node){
            return node;
        }
        return parent[node]=findpar(parent[node]); //path compression
    }
    
    void unionSize(int u,int v){
        //find ultimate parents
        int pu=findpar(u);
        int pv=findpar(v);
        if(pu==pv){
            return;
        }
        //attach smaller to bigger
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
    
    void unionRank(int u,int v){
        //find ultimate parents
        int pu=findpar(u);
        int pv=findpar(v);
        if(pu==pv){
            return;
        }
        if(rank[pu]==rank[pv]){
            parent[pu]=pv;
            rank[pu]++;
        }else if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }else{
            parent[pv]=pu;
        }
    }
    
    
};

int main() {
	
}
