// elevation matrix
// rain starts falling at time 0
// at time t the water level across entire grid is t
// can swim hor and vert --->  IF ORIGNAL ELEVATION OF BOTH SQUARES IS LESS THAN OR EUQAL TO WATER LEVEL AT TIME t;
// we have to go from 0,0 to n-1,n-1


class Solution {
public:
    using vvi = vector<vector<int>>;
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vvi vis(n,vector<int>(n,0));

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});

        int time = grid[0][0];

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int elv = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(vis[row][col]) continue;
            time = max(time,elv);
            vis[row][col] = 1;

            if(row == n-1 && col == n-1) break;

            int dr[4] = {-1,0,1,0};
            int dc[4] = {0,1,0,-1};

            for(int i = 0 ; i<4 ; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr < n && nr >= 0 && nc < n && nc >=0 && vis[nr][nc] == 0){
                    pq.push({grid[nr][nc] , {nr,nc}});
                }
            }
        }

        return time;

    }
};
