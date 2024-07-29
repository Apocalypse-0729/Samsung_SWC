#include<bits/stdc++.h>
using namespace std;
int ans=INT_MAX;
int companies;
void dfs(int i, vector<int> &mines, vector<int> &vis, int sum, int minV, int maxV, int nodes){
    if(vis[i]){
        int newMin=min(sum,minV);
        int newMax=max(sum,maxV);
        if(nodes==companies-1){
            ans=min(ans,newMax-newMin);
        }
        return;
    }
    vis[i]=1;
    int j=(i+1)%mines.size();
    dfs(j,mines,vis,sum+mines[i],minV,maxV,nodes);
    int newMin=min(sum,minV);
    int newMax=max(sum,maxV);
    dfs(j,mines,vis,mines[i],newMin,newMax,nodes+1);
    vis[i]=0;
    return;
}
void oilMines(){
    int n,m; cin>>n>>m;
    vector<int> mines(m);
    for(int i=0; i<m; i++) cin>>mines[i];
    vector<int> vis(m,0);
    companies=n;
    for(int i=0; i<m; i++){
        dfs(i,mines,vis,0,INT_MAX,INT_MIN,0);
    }
    cout<<ans<<endl;
    
}
int main(){
    int t; cin>>t; 
    while(t--){
        oilMines();
    }
}
