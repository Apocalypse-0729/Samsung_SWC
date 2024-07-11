#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int left;
    int right;
    int up;
    int down;
};
void allot(int n,int i, int j, vector<vector<node>> &move){
    node cell;
    if(n==1){
        cell.left=1;
        cell.right=1;
        cell.up=1;
        cell.down=1;
    }
    else if(n==2){
        cell.left=0;
        cell.right=0;
        cell.up=1;
        cell.down=1;
    }
    else if(n==3){
        cell.left=1;
        cell.right=1;
        cell.up=0;
        cell.down=0;
    }
    else if(n==4){
        cell.left=0;
        cell.right=1;
        cell.up=1;
        cell.down=0;
    }
    else if(n==5){
        cell.left=0;
        cell.right=1;
        cell.up=0;
        cell.down=1;
    }
    else if(n==6){
        cell.left=1;
        cell.right=0;
        cell.up=0;
        cell.down=1;
    }
    else if(n==7){
        cell.left=1;
        cell.right=0;
        cell.up=1;
        cell.down=0;
    }
    else{
        cell.left=0;
        cell.right=0;
        cell.up=0;
        cell.down=0;
    }
    move[i][j]=cell;
}
bool isValid(int n,int m,int r,int c){
    return r>=0 && r<n && c>=0 && c<m;
}
int endoscope(){
    int n,m,r,c,len;
    cin>>n>>m>>r>>c>>len;
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> grid(n,vector<int>(m));
    vector<vector<node>> move(n,vector<node>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
            allot(grid[i][j],i,j,move);
        }
    }
    if(grid[r][c]==0) return 0;
    queue<vector<int>> q;
    vis[r][c]=1;
    int cnt=1;
    q.push({r,c,1});
    while(!q.empty()){
        int row=q.front()[0];
        int col=q.front()[1];
        int steps=q.front()[2];
        // cout<<"run"<<endl;
        q.pop();
        if(1+steps<=len){
            if(isValid(n,m,row-1,col) && !vis[row-1][col] && move[row][col].up && move[row-1][col].down){
                q.push({row-1,col,steps+1});
                vis[row-1][col]=1;
                cnt++;
            }
            if(isValid(n,m,row+1,col) && !vis[row+1][col] && move[row+1][col].up && move[row][col].down){
                q.push({row+1,col,steps+1});
                vis[row+1][col]=1;
                cnt++;
            }
            if(isValid(n,m,row,col-1) && !vis[row][col-1] && move[row][col].left && move[row][col-1].right){
                q.push({row,col-1,steps+1});
                vis[row][col-1]=1;
                cnt++;
            }
            if(isValid(n,m,row,col+1) && !vis[row][col+1] && move[row][col+1].left && move[row][col].right){
                q.push({row,col+1,steps+1});
                vis[row][col+1]=1;
                cnt++;
            }
            // else{
            //     cout<<"NO RUN"<<endl;
            // }
        }
    }
    return cnt;
}

int main(){
    int t; cin>>t;
    while(t--){
        // cout<<"Case#"<<t<<endl;
        cout<<endoscope()<<endl;
    }
    return 0;
}
