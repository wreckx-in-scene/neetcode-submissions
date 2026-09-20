class Solution {
public:
    int lastStoneWeight(vector<int>& nums) {
        priority_queue<int> pq(nums.begin() , nums.end());
        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            int res = abs(x-y);
            if(res == 0) continue;
            pq.push(res);
        }

        return (pq.size() == 0) ? 0 : pq.top();
    }
};
