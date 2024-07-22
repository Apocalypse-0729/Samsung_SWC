#include<bits/stdc++.h>
using namespace std;

int dj(int sr, int sc, vector<vector<int>> &grid, vector<pair<int,int>> &ele){
    int n=grid.size();
    vector<vector<int>> dist(n,vector<int>(n,1e9));
    dist[sr][sc]=0;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
    q.push({0,{sr,sc}});
    while(!q.empty()){
        int row=q.top().second.first;
        int col=q.top().second.second;
        int dis=q.top().first;
        q.pop();
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int i=0; i<4; i++){
            int nrow=row+dx[i];
            int ncol=col+dy[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && 1+dis<dist[nrow][ncol]){
                dist[nrow][ncol]=1+dis;
                q.push({dis+1,{nrow,ncol}});
            }
        }
    }
    int maxi=INT_MIN;
    for(int i=0; i<ele.size(); i++){
        int row=ele[i].first-1;
        int col=ele[i].second-1;
        if(dist[row][col]==1e9) return INT_MAX;
        else{
            maxi=max(maxi,dist[row][col]);
        }
    }
    return maxi;
}
void rareElement(){
    int n,k; cin>>n>>k;
    vector<vector<int>> grid(n,vector<int>(n,0));
    vector<pair<int,int>> ele(k);
    for(int i=0; i<k;i++){
        cin>>ele[i].first>>ele[i].second;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    int ans=INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j]==1){
                int res=dj(i,j,grid,ele);
                if(res!=INT_MAX) ans=min(ans,res);
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        rareElement();
    }
}
