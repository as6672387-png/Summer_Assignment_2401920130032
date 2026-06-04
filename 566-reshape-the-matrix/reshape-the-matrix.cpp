class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();

        if (m * n != r * c) {
            return mat;
        }

        vector<vector<int>> result(r, vector<int>(c));

        for (int idx = 0; idx < m * n; idx++) {
            result[idx / c][idx % c] =
                mat[idx / n][idx % n];
        }

        return result;
        
    }
};