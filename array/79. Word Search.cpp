class Solution {
public:
    bool helper(vector<vector<char>>& board, vector<vector<bool>>& vis,
                string word, int i, int j, int k) {
        if (k == word.size())
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || vis[i][j] || board[i][j] != word[k])
            return false;
        vis[i][j] = true;
        bool found = helper(board, vis, word, i - 1, j, k + 1) ||
                     helper(board, vis, word, i, j - 1, k + 1) ||
                     helper(board, vis, word, i + 1, j, k + 1) ||
                     helper(board, vis, word, i, j + 1, k + 1);
        vis[i][j] = false;
        ;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (helper(board, vis, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
