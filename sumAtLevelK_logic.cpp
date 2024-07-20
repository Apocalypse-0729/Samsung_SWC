#include<bits/stdc++.h>
using namespace std;

void sumLevelK(){
    int n; cin>>n;
    string s; cin>>s;
    vector<vector<int>> ans(2,vector<int>(100,0));
    int size=0;
    int level=0;
    int commit=0;
    int neg=0;
    int temp=0;
    for(int i=0; i<int(s.size()); i++){
        if(s[i]=='(' || s[i]==')'){
            if(commit==1){
                if(neg==1){
                    temp=temp*-1;
                    neg=0;
                }
                ans[0][size]=level;
                ans[1][size]=temp;
                size++;
                temp=0;
            }
            if(s[i]=='(') level++;
            else if(s[i]==')') level--;
            commit=0;
        }
        else if(s[i]=='-'){
            neg=1;
            commit=1;
        }
        else{
            temp=temp*10+(s[i]-'0');
            commit=1;
        }
    }
    int sum=0;
    for(int i=0; i<size;i++){
        if(ans[0][i]==n+1) sum+=ans[1][i];
    }
    cout<<sum<<endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        sumLevelK();
    }
}
