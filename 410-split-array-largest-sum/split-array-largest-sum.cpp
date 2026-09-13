class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        long long lo = *max_element(nums.begin(), nums.end());
        long long hi = accumulate(nums.begin(), nums.end(), 0LL);

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            int parts = 1;
            long long sum = 0;

            for (int x : nums) {
                if (sum + x > mid) {
                    parts++;
                    sum = x;
                } else {
                    sum += x;
                }
            }

            if (parts <= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};