#include <bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V);
        for(int i=0; i<V; i++) dist[i]=INT_MAX;
        pq.push({0,S});
        dist[S]=0;
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                if(dis+it[1]<dist[it[0]]){
                    dist[it[0]]=it[1]+dis;
                    pq.push({dist[it[0]],it[0]});
                }
            }
        }
    return dist;
  // Code here
}
int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int sx,sy,dx,dy;
        cin>>sx>>sy>>dx>>dy;
        vector<vector<int>> adj[2*n+2];
        vector<vector<int>> info(n,vector<int>(5,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<5; j++) cin>>info[i][j];
        }
        map<pair<int,int>,vector<int>> wormHolePath;
        map<pair<int,int>,int> wormHoleNode;
        
        for(auto it:info){
            wormHolePath[{it[0],it[1]}]={it[2],it[3],it[4]};
        }
        
        wormHoleNode[{sx,sy}]=0;
        wormHoleNode[{dx,dy}]=2*n+1;
        int i=1;
        for(auto it:info){
            if(wormHoleNode.find({it[0],it[1]})==wormHoleNode.end() && make_pair(it[0],it[1])!=make_pair(dx,dy)){
                wormHoleNode[{it[0],it[1]}]=i; i++;
            }
            if(wormHoleNode.find({it[2],it[3]})==wormHoleNode.end() && make_pair(it[2],it[3])!=make_pair(dx,dy)){
                wormHoleNode[{it[2],it[3]}]=i; i++;
            }
        }
        
        for(auto u:wormHoleNode){
            for(auto v:wormHoleNode){
                if(u.first==v.first) continue;
                // int nu=wormHoleNode[u.first];
                // int nv=wormHoleNode[v.first];
                int dis=abs(u.first.first-v.first.first)+abs(v.first.second-u.first.second);
                if(wormHolePath.find(u.first)!=wormHolePath.end() && make_pair(wormHolePath[u.first][0],wormHolePath[u.first][1])==v.first){
                    adj[wormHoleNode[u.first]].push_back({wormHoleNode[v.first],wormHolePath[u.first][2]});
                    adj[wormHoleNode[v.first]].push_back({wormHoleNode[u.first],wormHolePath[u.first][2]});
                }
                else if(wormHolePath.find(v.first)!=wormHolePath.end() && make_pair(wormHolePath[v.first][0],wormHolePath[v.first][1])==u.first){
                    adj[wormHoleNode[v.first]].push_back({wormHoleNode[u.first],wormHolePath[v.first][2]});
                    adj[wormHoleNode[u.first]].push_back({wormHoleNode[v.first],wormHolePath[v.first][2]});
                }
                else{
                    adj[wormHoleNode[v.first]].push_back({wormHoleNode[u.first],dis});
                    adj[wormHoleNode[u.first]].push_back({wormHoleNode[v.first],dis});
                }
            }
        }
        // for (int i = 0; i < 2 * n + 2; i++) {
        //     cout << i << " :";
        //     for (auto it : adj[i]) {
        //         cout << " {" << it[0] << "," << it[1] << "} ";
        //     }
        //     cout << endl;
        // }
        vector<int> dist=dijkstra(2*n+2,adj,0);
        int end_node=wormHoleNode[{dx,dy}];
        // for(auto it:dist) cout<<it<<endl;
        cout<<dist[end_node]<<endl;
    }
    return 0;
}
