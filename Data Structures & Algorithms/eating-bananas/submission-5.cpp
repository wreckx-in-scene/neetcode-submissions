class Solution {
public:
    using ll = long long;
    ll check(vector<int>& piles, ll mid) {
        ll h = 0;

        for (int x : piles) {
            h += (1LL * x + mid - 1) / mid;
        }

        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        ll low = 1;
        ll high = *max_element(piles.begin(), piles.end());
        ll ans = high;

        while (low <= high) {
            ll mid = low + (high - low) / 2;

            if (check(piles, mid) <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};