class Solution {
public:
    using vvi = vector<vector<int>>;

    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int n = numCourses;

        vvi adj(n);

        for(auto it : pre){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }

        vector<int> in(n, 0);

        for(int i = 0; i < n; i++){
            for(auto it : adj[i]){
                in[it]++;
            }
        }

        queue<int> q;

        for(int i = 0; i < n; i++){
            if(in[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        int cnt = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);
            cnt++;

            for(auto next : adj[node]){
                in[next]--;

                if(in[next] == 0)
                    q.push(next);
            }
        }

        if(cnt == n) return ans;
        return {};
    }
};