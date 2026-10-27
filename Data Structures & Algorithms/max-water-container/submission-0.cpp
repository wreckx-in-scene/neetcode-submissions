class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int l = 0 , r = n-1;
        int maxi = INT_MIN;

        while(l<r){
            int water = (r-l) * min(h[l] , h[r]);
            maxi = max(maxi,water);
            if(h[l] < h[r]) l++;
            else if(h[l] > h[r]) r--;
            else{
                l++;
                r--;
            }
        }

        return maxi;
    }
};
