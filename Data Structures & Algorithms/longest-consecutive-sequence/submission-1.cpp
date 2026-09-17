class Solution {
   public:
    int longestConsecutive(vector<int>& a) {
        int n = a.size();

        unordered_set<int> st(a.begin() , a.end());

        int maxi = 0;
        for(auto x : st){
            if(st.count(x-1)) continue;
            int len = 1;
            int curr = x;
            while(st.count(curr+1)){
                len++;
                curr++;
            }

            maxi = max(len, maxi);
        }

        return maxi;
    }
};
