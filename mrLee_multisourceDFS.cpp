#include<bits/stdc++.h>
using namespace std;

int ans;
void dfs(int x,int value, int n, int nodes,vector<int> &vis,vector<vector<int>> &grid){
    if(n-1==nodes){
        // to handle that their exist a path between last to home node.
        if(grid[x][0]){
            ans=min(ans,value+grid[x][0]);
        }
    }
    for(int i=1; i<n; i++){
        // to handle that their exist a path between two nodes.
        if(!vis[i] && grid[x][i]!=0){
            vis[i]=1;
            dfs(i,value+grid[x][i],n,nodes+1,vis,grid);
            vis[i]=0;
        }
    }
}
void mrlee(){
    int n; cin>>n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    vector<int> vis(n,0);
    vis[0]=1;
    dfs(0,0,n,0,vis,grid);
    cout<<ans<<endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        ans=INT_MAX;
        mrlee();
    }
    return 0;
}
