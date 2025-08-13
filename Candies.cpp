#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int t; cin>>t;
  for(long long int i=1; i<=t; i++){
    long long int a,b,k; cin>>a>>b>>k;
    unordered_map<long long int,long long int> mp;
    bool Flag=true;
    long long int st=0;
    mp[min(a,b)]=st;
    cout<<"#"<<i<<" ";
    while(true){
      long long int mini=min(a,b);
      if(mini==0){
        cout<<0<<endl;
        Flag=false;
        break;
      }
      if(mini==a){
        a=a+mini;
        b=b-mini;
      }
      else{
        b=b+mini;
        a=a-mini;
      }
      st++;
      if(mp.find(min(a,b))!=mp.end()){
        break;
      }
      mp[min(a,b)]=st;
    }
    if(Flag){
      long long int check=(k-mp[min(a,b)])%(st-mp[min(a,b)]);
      for(auto it:mp){
        if(it.second==check){
          cout<<it.first<<"\n";
          break;
        }
      }
      
    }
  }
  return 0;
}
