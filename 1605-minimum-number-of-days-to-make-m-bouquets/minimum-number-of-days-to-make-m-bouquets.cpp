class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long need = 1LL * m * k;
        if (need > bloomDay.size()) return -1;

        int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());

        while (l < r) {
            int mid = l + (r - l) / 2;
            int bouquets = 0, flowers = 0;

            for (int day : bloomDay) {
                if (day <= mid) {
                    if (++flowers == k) {
                        bouquets++;
                        flowers = 0;
                    }
                } else {
                    flowers = 0;
                }
            }

            if (bouquets >= m)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }
};