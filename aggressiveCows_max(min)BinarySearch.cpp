class Solution {
public:
    bool check(vector<int> &stalls, int dist, int cows){
        int cntCows=1, lastCow=stalls[0];
        for(int i=1; i<stalls.size(); i++){
            if(stalls[i]-lastCow>=dist){
                cntCows++;
                lastCow=stalls[i];
            }
            if(cntCows>=cows) return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int lo=1, hi=stalls[n-1]-stalls[0];
        while(hi>=lo){
            int mid=(hi+lo)/2;
            if(check(stalls,mid,k)==true) lo=mid+1;
            else hi=mid-1;
        }
        return hi;
    }
};
