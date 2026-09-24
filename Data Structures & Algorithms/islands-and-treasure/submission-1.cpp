class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector(m,0));

        queue<pair<int,int>> q;

        //process the zeros
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();

            int dr[4] = {-1,0,1,0};
            int dc[4] = {0,1,0,-1};

            for(int i = 0 ; i<4 ; i++){
                int nr = row+dr[i];
                int nc = col+dc[i];

                if(nr<0 || nc<0 || nr>=n || nc>=m) continue;
                if(grid[nr][nc] == -1 || vis[nr][nc] == 1) continue;

                grid[nr][nc] = grid[row][col] + 1;
                vis[nr][nc] = 1;
                q.push({nr,nc});
            }

        }
    }
};
