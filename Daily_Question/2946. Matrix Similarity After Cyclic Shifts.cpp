class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        k = k % m;
        vector<vector<int>> temp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int col;
                if (i & 1)
                    col = (j + m - k) % m;
                else
                    col = (j + k) % m;
                temp[i][col] = mat[i][j];
            }
        }
        return mat == temp;
    }
};
