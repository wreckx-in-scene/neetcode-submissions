class Solution { 
public: 
    int orangesRotting(vector<vector<int>>& grid) { 
        int n = grid.size(); 
        int m = grid[0].size(); 

        vector<vector<int>> vis(n,vector<int>(m,0)); 
        queue<pair<int,int>> q; 

        int fresh = 0; 

        for(int i = 0 ; i<n ; i++){ 
            for(int j = 0 ; j<m ; j++){ 
                if(grid[i][j] == 2){ 
                    vis[i][j] = 1; 
                    q.push({i,j}); 
                } 
                else if(grid[i][j] == 1){ 
                    fresh++; 
                } 
            } 
        } 

        if(fresh == 0) return 0; 

        int time = 0; 

        int dr[4] = {-1,0,1,0}; 
        int dc[4] = {0,1,0,-1}; 

        while(!q.empty()){ 
            int sz = q.size(); 

            while(sz--){ 
                auto [r,c] = q.front(); 
                q.pop(); 

                for(int i = 0 ; i<4 ; i++){ 
                    int nr = r + dr[i]; 
                    int nc = c + dc[i]; 

                    if(nr<0 || nc<0 || nr>=n || nc>=m) continue; 
                    if(vis[nr][nc] || grid[nr][nc] != 1) continue; 

                    grid[nr][nc] = 2; 
                    vis[nr][nc] = 1; 
                    fresh--; 
                    q.push({nr,nc}); 
                } 
            } 

            time++; 
        } 

        if(fresh > 0) return -1; 
        return time - 1; 
    } 
};