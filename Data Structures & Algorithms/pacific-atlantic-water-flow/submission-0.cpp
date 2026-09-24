class Solution { 
public: 
    using vvi = vector<vector<int>>; 
    using vi = vector<int>; 

    void dfs(int r, int c, vvi& h, vvi& vis) {
        int n = h.size();
        int m = h[0].size();

        vis[r][c] = 1;

        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,1,0,-1};

        for(int i = 0 ; i<4 ; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m ||
               vis[nr][nc] || h[nr][nc] < h[r][c])
                continue;

            dfs(nr,nc,h,vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) { 
        int n = h.size(); 
        int m = h[0].size(); 

        vvi res; 
        vvi atlantic(n,vi(m,0)); 
        vvi pacific(n,vi(m,0)); 

        for(int i = 0 ; i<n ; i++) {
            dfs(i,0,h,pacific);
            dfs(i,m-1,h,atlantic);
        }

        for(int j = 0 ; j<m ; j++) {
            dfs(0,j,h,pacific);
            dfs(n-1,j,h,atlantic);
        }

        for(int i = 0 ; i<n ; i++) {
            for(int j = 0 ; j<m ; j++) {
                if(atlantic[i][j] && pacific[i][j])
                    res.push_back({i,j});
            }
        }

        return res; 
    } 
};