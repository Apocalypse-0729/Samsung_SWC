#include<bits/stdc++.h>
using namespace std;
/*
https://www.geeksforgeeks.org/samsung-interview-experience-set-40-campus-white-box-testing/
https://www.geeksforgeeks.org/samsung-rd-sri-noida-on-campus-interview-experience/
https://code.hackerearth.com/01ac52j?key=b462f0a802c8c1faf1d87f2b1353b9ce

Company  A  is discarding product numbers that contain few specific digits a specific number of time or 
more than that. You are given a range and you need to find product numbers that are possible.

Example-

Range: 24 to 12943

Numbers that should not come: 1, 3, 5
Number of times these number should not occur: 3 or more

In above case all two digit numbers are valid.

In three digit: 111, 113, 115, 311, 331, 333, 511, 533, 555 are not valid.

In four digit: All the numbers containing above 3 digit numbers are not valid.

Eg: 11223 is not valid, 11222 is valid.
*/
void omniousNumber(){
    int a,b,k; cin>>a>>b>>k;
    int n;
    cin>>n;
    vector<int> notvalid(n,0);
    for(int i=0; i<n; i++) cin>>notvalid[i];
    int ans=0;
    for(int i=a; i<=b; i++){
        int num=i;
        vector<int> digits(10,0);
        while(num){
            digits[num%10]++;
            num=num/10;
        }
        int check=0;
        for(int i=0; i<n; i++){
            check+=(digits[notvalid[i]]);
        }
        if(check<k) ans++;
    }
    cout<<ans<<endl;
}
int main(){
    int t; cin>>t;
    while(t--){
        omniousNumber();
    }
}
