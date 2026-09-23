class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();

        if(r < 0 || r >= n || c < 0 || c >= m || 
           vis[r][c] || grid[r][c] == '0') {
            return;
        }

        vis[r][c] = 1;

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            dfs(r + dr[i], c + dc[i], grid, vis);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    dfs(i, j, grid, vis);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};