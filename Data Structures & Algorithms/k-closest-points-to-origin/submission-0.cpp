class Solution {
public:
    using P = pair<int, pair<int,int>>;

    int getDist(int x, int y){
        return x*x + y*y;
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<P> pq;

        for(auto p : points){
            int x = p[0];
            int y = p[1];

            int dist = getDist(x, y);

            pq.push({dist, {x, y}});

            if(pq.size() > k)
                pq.pop();
        }

        vector<vector<int>> res;

        while(!pq.empty()){
            auto [dist, point] = pq.top();
            pq.pop();

            res.push_back({point.first, point.second});
        }

        return res;
    }
};