class Solution {
public:
    vector<int> pge(vector<int>& a){
        int n = a.size();
        vector<int> dp(n);

        for(int i = 0 ; i<n ; i++) dp[i] = a[i];

        for(int i = 1 ; i<n ; i++) dp[i] = max(dp[i],dp[i-1]);

        for(int i = 0 ; i<n ; i++){
            if(dp[i] == a[i]) dp[i]=-1;
        }

        return dp;
    }

    vector<int> nge(vector<int>& a){
        int n = a.size();
        vector<int> dp(n);

        //base case
        for(int i = 0 ; i<n ; i++) dp[i]= a[i];

        for(int i = n-2 ; i>=0 ; i--) dp[i] = max(dp[i] , dp[i+1]);

        for(int i = 0 ; i<n ; i++){
            if(dp[i] == a[i]) dp[i] = -1;
        }

        return dp;
    }
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> pg = pge(h);
        vector<int> ng = nge(h);

        int ans = 0;
        for(int i = 0 ; i<n ; i++){
            if(pg[i] == -1 || ng[i] == -1) continue;
            int water = min(pg[i],ng[i]) - h[i];
            ans += water;
        }

        return ans;

    }
};
