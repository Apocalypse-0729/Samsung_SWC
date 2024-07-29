#include<bits/stdc++.h>
using namespace std;

void doct(){
    int n,m,t; cin>>n>>m>>t;
    vector<vector<pair<int,double>>> adj(n+1);
    for(int i=0; i<m; i++){
        int u,v; double prob;
        cin>>u>>v>>prob;
        adj[u].push_back({v,prob});
    }
    if(t<10){
        cout<<1<<" "<<1<<endl;
        return;
    }
    vector<double> ans(n+1);
    ans[1]=1;
    t=t-10;
    while(t>=0){
        t-=10;
        vector<double> temp(n+1,0);
        for(int i=1; i<=n; i++){
            if(ans[i]!=0){
                for(auto it:adj[i]){
                    int node=it.first;
                    double prob=it.second;
                    temp[node]+=(ans[i]*prob);
                }
            }
        }
        ans=temp;
    }
    int finalDiv=0;
    double finalProb=0;
    for(int i=1; i<=n; i++){
        if(ans[i]>=finalProb){
            finalProb=ans[i];
            finalDiv=i;
        }
    }
    cout<<finalDiv<<" "<<finalProb<<endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        doct();
    }
}
