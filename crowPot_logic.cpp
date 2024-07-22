#include<bits/stdc++.h>
using namespace std;

void crowPots(){
    int n; cin>>n;
    vector<int> pot(n);
    for(int i=0; i<n; i++){
        cin>>pot[i];
    }
    int k; cin>>k;
    sort(pot.begin(),pot.end());
    int ans=0;
    for(int i=n-1; i>0; i--){
        pot[i]=max(0,pot[i]-pot[i-1]);
    }
    for(int i=0; i<k; i++){
        ans+=(n-i)*pot[i];
    }
    cout<<ans<<endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        crowPots();
    }
}
