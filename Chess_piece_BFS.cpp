#include <bits/stdc++.h>
using namespace std;


// can be done in both ways!
// 1. using BFS
// 2. using Dijkstra's Algorithm

int chess_piece(){
    int n,m; cin>>n>>m;
    int sr,sc,dr,dc;
    cin>>sr>>sc>>dr>>dc;
    vector<vector<int>> vis(n+1,vector<int>(m+1,0));
    queue<pair<int,pair<int,int>>> q;
    int ans=-1;
    int move[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
    q.push({0,{sr,sc}});
    while(!q.empty()){
        int row=q.front().second.first;
        int col=q.front().second.second;
        int steps=q.front().first;
        q.pop();
        for(int i=0; i<8; i++){
            int nrow=row+move[i][0];
            int ncol=col+move[i][1];
            if(nrow==dr && ncol==dc) return steps+1;
            if(nrow>=1 && nrow<=n && ncol>=1 && ncol<=m && !vis[nrow][ncol]){
                vis[nrow][ncol]=1;
                q.push({steps+1,{nrow,ncol}});
            }
        }
    }
    return -1;
}

int main(){
    int t; cin>>t;
    while(t--){
        cout<<chess_piece()<<endl;
    }
    return 0;
}
