class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));
        if (k == 1)
            return ans;
        for (int i = 0; i < m && i < m - k + 1; i++) {
            for (int j = 0; j < n && j < n - k + 1; j++) {
                vector<int> temp;
                for (int p = i; p < i + k; p++) {
                    for (int l = j; l < j + k; l++) {
                        temp.push_back(grid[p][l]);
                    }
                }
                sort(temp.begin(), temp.end());
                temp.erase(unique(temp.begin(), temp.end()), temp.end());
                int diff = INT_MAX;
                for (int a = 1; a < temp.size(); a++) {
                    diff = min(diff, abs(temp[a] - temp[a - 1]));
                    if(diff==0) break;
                }
                if (diff == INT_MAX)
                    ans[i][j] = 0;
                else
                    ans[i][j] = diff;
            }
        }
        return ans;
    }
};
