class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> nums(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
            nums[i][0] = i;
        for (int i = 0; i <= m; i++)
            nums[0][i] = i;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1])
                    nums[i][j] = nums[i - 1][j - 1];
                else {
                    nums[i][j] = 1+min(
                        {nums[i - 1][j - 1], nums[i - 1][j], nums[i][j - 1]});
                }
            }
        }
        return nums[n][m];
    }
};
