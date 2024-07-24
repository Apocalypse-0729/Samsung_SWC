#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<double>> &adj, int time, double prob, vector<double> &ans){
    if(time<=0){
        ans[node]+=prob;
        return;
    }
    int n=adj.size();
    for(int i=1; i<=n-1; i++){
        if(adj[node][i]!=0){
            prob=prob*adj[node][i];
            dfs(i,adj,time-10,prob,ans);
            prob=prob/adj[node][i];
        }
    }
}
void doctProb(){
    int n,m,t; cin>>n>>m>>t;
    vector<vector<double>> adj(n+1,vector<double>(n+1,0.0));
    for(int i=0; i<m; i++){
        int u,v; double prob; cin>>u>>v>>prob;
        adj[u][v]=prob;
    }
    vector<double> ans(n+1,0);
    dfs(1,adj,t,1.0,ans);
    double final_prob=0.0;
    int final_div=0;
    
    for(int i=1; i<=n; i++){
        if(ans[i]>final_prob){
            final_prob=ans[i];
            final_div=i;
        }
    }
    cout<<final_div<<" "<<final_prob<<endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        doctProb();
    }
    return 0;
}
