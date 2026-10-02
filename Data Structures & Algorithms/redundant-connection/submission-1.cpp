class Solution {
public:
    using vi = vector<int>;
    using vvi = vector<vi>;

    bool bfs(int src, int target, vvi& adj) {
        vi vis(adj.size(), 0);
        queue<int> q;

        q.push(src);
        vis[src] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            if(node == target) return true;

            for(auto next : adj[node]) {
                if(!vis[next]) {
                    vis[next] = 1;
                    q.push(next);
                }
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vvi adj(n + 1);

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];

            if(bfs(u, v, adj))
                return e;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {};
    }
};