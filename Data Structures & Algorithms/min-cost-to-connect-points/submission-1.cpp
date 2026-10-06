// given array points with x,y 
// the connecting cost is manhattan
// return the min cost to connect all points 

// to make a mst  ,  use prims algo for total mst wt


class Solution {
public:
    using p = pair<int,int>;
    using vp = vector<p>;
    using vi = vector<int>;
    struct Point{
        int x;
        int y;
    };

    int manhattan(Point &p1 , Point &p2){
        return abs(p1.x - p2.x) + abs(p1.y - p2.y);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        // make an edges array with all edges
        vector<Point> pointSet;
        int n = points.size();
        for(int i = 0 ; i<n ; i++){
            int x = points[i][0];
            int y = points[i][1];

            pointSet.push_back({x,y});
        }

        //build adj
        vector<vp> adj(n);
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                if(i == j) continue;
                Point p1 = pointSet[i];
                Point p2 = pointSet[j];

                int dist = manhattan(p1,p2);
                adj[i].push_back({j,dist});

            }
        }

        //apply prims algo
        vi vis(n,0);
        priority_queue<p,vector<p>, greater<p>> pq;
        pq.push({0,0});

        int sum = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(vis[node]) continue;
            vis[node] = 1;
            sum += wt;

            for(auto it : adj[node]){
                int next = it.first;
                int nextwt = it.second;

                if(vis[next] == 0){
                    pq.push({nextwt , next});
                }
            }
        }

        return sum;
    }
};
