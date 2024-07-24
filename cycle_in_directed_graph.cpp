// Function to detect cycle in a directed graph.
    bool dfsCheck(int node,vector<int> adj[],vector<int> &vis,vector<int> &pathVis){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfsCheck(it,adj,vis,pathVis)) return true;
            }
            else if(pathVis[it]) return true;
        }
        pathVis[node]=0;
        return false;
    }
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        vector<int> vis(n,0);
        vector<int> pathVis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfsCheck(i,adj,vis,pathVis)) return true;
            }
        }
        return false;
    }
