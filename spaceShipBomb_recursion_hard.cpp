#include<bits/stdc++.h>
using namespace std;

int ans=0;
bool bombUsed=false;
int safeRows=0;
int coins=0;

void getMaxCoins(int row, int col, vector<vector<int>> &grid,int safeRows, bool bombUsed, int coins){
    int n=grid.size();
    if(row>=0 && col>=0 && col<n){
        if(grid[row][col]==1 || grid[row][col]==0){
            int newcoins=coins;
            if(grid[row][col]==1){
                newcoins++;
            }
            if(bombUsed){
                safeRows--;
            }
            getMaxCoins(row-1,col-1,grid,safeRows,bombUsed,newcoins);
            getMaxCoins(row-1,col,grid,safeRows,bombUsed,newcoins);
            getMaxCoins(row-1,col+1,grid,safeRows,bombUsed,newcoins);
        }
        else if(grid[row][col]==2){
            if(bombUsed && safeRows<=0){
                ans=max(ans,coins);
                return;
            }
            else if(bombUsed && safeRows>0){
                safeRows--;
                getMaxCoins(row-1,col-1,grid,safeRows,bombUsed,coins);
                getMaxCoins(row-1,col,grid,safeRows,bombUsed,coins);
                getMaxCoins(row-1,col+1,grid,safeRows,bombUsed,coins);   
            }
            else{
                bombUsed=true;
                safeRows=4;
                getMaxCoins(row-1,col-1,grid,safeRows,bombUsed,coins);
                getMaxCoins(row-1,col,grid,safeRows,bombUsed,coins);
                getMaxCoins(row-1,col+1,grid,safeRows,bombUsed,coins);   
            }
        }
    }
    else{
        ans=max(ans,coins);
        return;
    }
}
void spaceShipBomb(){
    int n; cin>>n;
    vector<vector<int>> grid(n,vector<int>(5,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            cin>>grid[i][j];
        }
    }
    getMaxCoins(n-1,1,grid,safeRows,bombUsed,coins);
    getMaxCoins(n-1,2,grid,safeRows,bombUsed,coins);
    getMaxCoins(n-1,3,grid,safeRows,bombUsed,coins);
    
    cout<<ans<<endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        spaceShipBomb();
    }
}
