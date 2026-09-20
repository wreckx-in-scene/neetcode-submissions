class KthLargest {
public:
    int k; 
    priority_queue<int,vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        
        for(auto x : nums){
            add(x);
        }
    }
    int add(int val) {
        pq.push(val);

        while(pq.size() > k){
            pq.pop();
        }

        return pq.top();
    }
};
