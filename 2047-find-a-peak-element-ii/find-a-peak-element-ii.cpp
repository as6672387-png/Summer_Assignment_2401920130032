class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int lo = 0, hi = m - 1;

        while (lo <= hi) {
            int col = lo + (hi - lo) / 2;
            int row = 0;

            for (int i = 1; i < n; i++) {
                if (mat[i][col] > mat[row][col])
                    row = i;
            }

            int left = col > 0 ? mat[row][col - 1] : -1;
            int right = col + 1 < m ? mat[row][col + 1] : -1;

            if (mat[row][col] > left && mat[row][col] > right)
                return {row, col};

            if (right > mat[row][col])
                lo = col + 1;
            else
                hi = col - 1;
        }

        return {-1, -1};
    }
};