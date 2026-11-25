class Solution {
public:
    bool bfs(vector<vector<int>>&adj,int n,vector<int>&indegree){
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;
            for(auto v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return count==n;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        int n = numCourses;
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);

        for(auto it:prereq){
            int u = it[1];
            int v = it[0];

            adj[u].push_back(v);
            indegree[v]++;
        }
        return bfs(adj,n,indegree);
    }
};