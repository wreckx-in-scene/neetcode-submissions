class Solution {
public:
    using vi = vector<int>;
    using vvi = vector<vi>;
    void dfs(int i , vvi& adj , vi& vis){
        vis[i] = 1;

        for(auto next : adj[i]){
            if(!vis[next]) dfs(next,adj,vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& e) {
        vvi adj(n);
        for(auto it : e){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vi vis(n);
        int cnt = 0;
        for(int i = 0 ; i<n ; i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }

        return cnt;
    }
};
