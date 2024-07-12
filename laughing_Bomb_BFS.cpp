#include<bits/stdc++.h>
using namespace std;

void laughingBomb(){
    int n,m; cin>>m>>n;
    vector<vector<int>> grid(n,vector<int>(m));
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    int sr,sc; cin>>sr>>sc;
    queue<vector<int>> q;
    q.push({sr,sc,1});
    vis[sr][sc]=1;
    int ans=0;
    while(!q.empty()){
        int r=q.front()[0];
        int c=q.front()[1];
        int steps=q.front()[2];
        ans=max(ans,steps);
        q.pop();
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int i=0; i<4; i++){
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]){
                q.push({nr,nc,steps+1});
                vis[nr][nc]=1;
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t; cin>>t;
     // Initialize ans to 0
    while(t--){
        laughingBomb();
    }
    return 0;
}
