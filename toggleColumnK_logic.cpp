#include<bits/stdc++.h>
using namespace std;

void toggleColumn(){
    int n,m; cin>>n>>m;
    vector<vector<int>> grid(n,vector<int>(m,0));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }
    map<string,int> mp;
    int k; cin>>k;
    for(int i=0; i<n; i++){
        string temp="";
        for(int j=0; j<m; j++){
            temp+=(grid[i][j]+'0');
        }
        mp[temp]++;
    }
    int ans=0;
    for(auto it:mp){
        // cout<<it.first<<" "<<it.second<<endl;
    }
    for(auto it:mp){
        string s=it.first;
        int freq=it.second;
        int num_zeroes=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0') num_zeroes++;
        }
        if(abs(k-num_zeroes)%2==0 && k>=num_zeroes){
            ans=max(ans,freq);
        }
    }
    cout<<ans<<endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        toggleColumn();
    }
}
