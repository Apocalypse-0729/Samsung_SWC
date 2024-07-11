#include <bits/stdc++.h>
using namespace std;


int frogJump(){
    int n; cin>>n;
    int sr,sc,dr,dc;
    vector<vector<int>> grid(n,vector<int>(n));
    queue<vector<int>> q;
    vector<vector<int>> vis(n,vector<int>(n,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    cin>>sr>>sc>>dr>>dc;
    q.push({sr,sc,0});
    while(!q.empty()){
        int row=q.front()[0];
        int col=q.front()[1];
        int steps=q.front()[2];
        if(row==dr && col==dc) return steps;
        q.pop();
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        for(int i=0; i<4; i++){
            int nrow=row+dx[i];
            int ncol=col+dy[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol]){
                if(i==0 || i==1){
                    q.push({nrow,ncol,steps+1});
                }
                if(i==2 || i==3){
                    q.push({nrow,ncol,steps});
                }
                vis[nrow][ncol]=1;
            }
        }
    }
    return -1;
}

int main(){
    int t; cin>>t;
    while(t--){
        // cout<<"Case#"<<t<<endl;
        cout<<frogJump()<<endl;
    }
    return 0;
}
