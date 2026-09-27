class Solution {
   public:
    void dfs(int r, int c, vector<vector<char>>& b, vector<vector<int>>& vis) {
        int n = b.size();
        int m = b[0].size();

        if (r < 0 || r >= n || c < 0 || c >= m || vis[r][c] || b[r][c] != 'O') return;

        vis[r][c] = 1;
        b[r][c] = 'S';

        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            dfs(r + dr[i], c + dc[i], b, vis);
        }
    }
    void solve(vector<vector<char>>& b) {
        int n = b.size();
        int m = b[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1) {
                    if (b[i][j] == 'O' && vis[i][j] == 0) dfs(i, j, b, vis);
                }

                if (j == 0 || j == m - 1) {
                    if (b[i][j] == 'O' && vis[i][j] == 0) dfs(i, j, b, vis);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (b[i][j] == 'S') b[i][j] = 'O';
                else if (b[i][j] == 'O') b[i][j] = 'X';
            }
        }
    }
};
