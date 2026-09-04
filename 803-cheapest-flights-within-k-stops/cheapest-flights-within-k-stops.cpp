// 

class Solution {
public:
    void bfs(vector<vector<pair<int,int>>>&graph, int src, int dst, int k,
             vector<vector<int>>&dist) {

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        dist[src][0] = 0;
        pq.push({0, src, 0});

        while(!pq.empty()) {
            auto [cost, u, stops] = pq.top();
            pq.pop();

            for(auto e : graph[u]) {
                int v = e.first;
                int wt = e.second;

                if(stops + 1 <= k + 1 &&
                   dist[v][stops + 1] > cost + wt) {

                    dist[v][stops + 1] = cost + wt;
                    pq.push({cost + wt, v, stops + 1});
                }
            }
        }
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> graph(n);

        for(auto edge : flights) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            graph[u].push_back({v,wt});
        }

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        bfs(graph, src, dst, k, dist);

        int ans = INT_MAX;

        for(int i = 0; i <= k + 1; i++)
            ans = min(ans, dist[dst][i]);

        return ans == INT_MAX ? -1 : ans;
    }
};