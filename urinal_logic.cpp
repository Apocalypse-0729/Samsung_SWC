#include<bits/stdc++.h>
using namespace std;

void urinal(){
    int n,k; cin>>n>>k;
    vector<int> ans(n,0);
    for(int i=1; i<=k; i++){
        int answer=0, len=0, last=0;
        for(int j=0; j<n; j++){
            if(ans[j]==0) len++;
            if(ans[j]==1) len=0;
            if(len>=answer){
                last=j;
                answer=len;
            }
        }
        int s=last-answer+1;
        int mid=(s+last)/2;
        ans[mid]=1;
    }
    for(int i=0; i<n; i++){
        cout<<ans[i];
    }
    cout<<endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        urinal();
    }
}
