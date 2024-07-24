bool bfsCheck(int n,int parent,vector<int> adj[],vector<int> &vis){
        vis[n]=1;
        queue<pair<int,int>> q;
        q.push({n,parent});
        while(!q.empty()){
            int node=q.front().first;
            int parentNode=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,node});
                }
                else if(it!=parentNode){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(bfsCheck(i,-1,adj,vis)==true) return true;
            }
        }
        return false;
