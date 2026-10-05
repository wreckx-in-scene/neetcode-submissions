class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
        }

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        vector<int> dist(n + 1, INT_MAX);

        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > dist[node]) continue;

            for(auto it : adj[node]){
                int next = it.first;
                int wt = it.second;

                int newDist = d + wt;

                if(dist[next] > newDist){
                    dist[next] = newDist;
                    pq.push({newDist, next});
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};