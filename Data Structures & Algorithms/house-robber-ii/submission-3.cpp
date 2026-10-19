class Solution {
public:
    int helper(vector<int>& nums, int l, int r) {
        int n = r - l + 1;

        if(n == 1) return nums[l];

        vector<int> dp(n + 1, 0);

        dp[1] = nums[l];
        dp[2] = max(nums[l], nums[l + 1]);

        for(int i = 3; i <= n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[l + i - 1]);
        }

        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        int x = helper(nums, 0, n - 2);
        int y = helper(nums, 1, n - 1);

        return max(x, y);
    }
};