#include<bits/stdc++.h>
using namespace std;

int ans;
void dfs(int x,int y,int value, int n, int nodes,vector<int> &vis,vector<pair<int,int>> &grid){
    if(n==nodes){
        ans=min(ans,value+abs(x-grid[n+1].first)+abs(y-grid[n+1].second));
    }
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(grid[i].first,grid[i].second,value+abs(x-grid[i].first)+abs(y-grid[i].second),n,nodes+1,vis,grid);
            vis[i]=0;
        }
    }
}
void mrKim(){
    int n; cin>>n;
    vector<pair<int,int>> grid(n+2);
    cin>>grid[0].first>>grid[0].second>>grid[n+1].first>>grid[n+1].second;
    for(int i=1; i<=n; i++){
        cin>>grid[i].first>>grid[i].second;
    }
    vector<int> vis(n+2,0);
    vis[0]=1;
    dfs(grid[0].first,grid[0].second,0,n,0,vis,grid);
    cout<<ans<<endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        ans=INT_MAX;
        mrKim();
    }
    return 0;
}
