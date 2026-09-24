class Solution {
   public:
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        // check valid cell
        int n = grid.size();
        int m = grid[0].size();
        if (r < 0 || r >= n || c < 0 || c >= m || vis[r][c] == 1 || grid[r][c] == 0) {
            return 0;
        }

        //mark the cell
        vis[r][c] = 1;

        int area = 1;

        //dir
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};

        for(int i = 0 ; i<4 ; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];

            area += dfs(nr,nc,grid,vis);
        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == 1) {
                    int maxi = dfs(i,j,grid,vis);
                    ans = max(ans, maxi);
                }
            }
        }

        return ans;
    }
};
