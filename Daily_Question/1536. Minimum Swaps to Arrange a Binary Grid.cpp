class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> tz(n, 0);

        // trailing zeros for each row
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) cnt++;
            tz[i] = cnt;
        }

        int swaps = 0;
        for (int i = 0; i < n; i++) {
            int need = n - 1 - i;
            int j = i;
            while (j < n && tz[j] < need) j++;
            if (j == n) return -1;

            // bubble row j up to i
            while (j > i) {
                swap(tz[j], tz[j - 1]);
                swaps++;
                j--;
            }
        }
        return swaps;
    }
};
