class Solution {
public:
    bool cycle(int src,int dest,vector<vector<int>>&adj,int n){
        queue<pair<int,int>>q;
        vector<bool>vis(n+1,false);
        vis[src]=true;
        q.push({src,-1});
        while(!q.empty()){
            int u = q.front().first;
            int parent = q.front().second;
            q.pop();
            if(u==dest) return true;
            for(auto v:adj[u]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push({v,u});
                }else if(v!=parent){
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>adj(n+1);

        for(auto ed:edges){
            int u = ed[0];
            int v = ed[1];

            if(cycle(u,v,adj,n)){
                return {u,v};
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};