class Solution {
public:
    using vi = vector<int>;
    using vvi = vector<vi>;

    bool bfs(int src, vvi& adj, vi& vis, int& cnt){
        int n = vis.size();
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src, -1});

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            cnt++;

            for(auto next : adj[node]){
                if(!vis[next]){
                    vis[next] = 1;
                    q.push({next, node});
                }
                else if(next != parent){
                    return true;
                }
            }
        }

        return cnt != n;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vvi adj(n);

        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vi vis(n, 0);
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(bfs(i, adj, vis, cnt))
                    return false;
            }
        }

        return true;
    }
};