#include<bits/stdc++.h>
using namespace std;

int ans;
void dfs(int x,int y, int value, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<vector<int>> &path){
    int n=grid.size();
    if(x==n-1 && y==n-1){
        if(value>=ans){
            ans=value;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(vis[i][j]){
                        path[i][j]=3;
                    }
                    else path[i][j]=grid[i][j];
                }
            }
        }
        return;
    }
    else{
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0; i<4; i++){
            int nr=x+dx[i];
            int nc=y+dy[i];
            if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]!=1){
                if(grid[nr][nc]==2){
                    vis[nr][nc]=1;
                    dfs(nr,nc,value+1,vis,grid,path);
                    vis[nr][nc]=0;
                }
                if(grid[nr][nc]==0){
                    vis[nr][nc]=1;
                    dfs(nr,nc,value,vis,grid,path);
                    vis[nr][nc]=0;
                }
            }
        }
    }
}
void jewelMaze(){
    int n; cin>>n;
    vector<vector<int>> grid(n,vector<int>(n));
    vector<vector<int>> vis(n,vector<int>(n,0));
    vector<vector<int>> path(n,vector<int>(n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    vis[0][0]=1;
    if(grid[0][0]==2){
        dfs(0,0,1,vis,grid,path);
    }
    else{
        dfs(0,0,0,vis,grid,path);
    }
    cout<<ans<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
int main(){
    int t; cin>>t;
     // Initialize ans to 0
    while(t--){
        ans = 0;
        jewelMaze();
    }
    return 0;
}
