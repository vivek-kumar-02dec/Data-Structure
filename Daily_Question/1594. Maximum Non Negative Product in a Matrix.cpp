class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long>> mini(n, vector<long long>(m, 0));
        vector<vector<long long>> maxi(n, vector<long long>(m, 0));
        mini[0][0]=grid[0][0];
        maxi[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            mini[i][0]=mini[i-1][0]*grid[i][0];
            maxi[i][0]=maxi[i-1][0]*grid[i][0];
        }
        for(int i=1;i<m;i++){
            mini[0][i]=mini[0][i-1]*grid[0][i];
            maxi[0][i]=maxi[0][i-1]*grid[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                long long val=grid[i][j];
                long long topm=maxi[i-1][j]*val;
                long long topn=mini[i-1][j]*val;
                long long leftm=maxi[i][j-1]*val;
                long long leftn=mini[i][j-1]*val;
                maxi[i][j]=max({topm,topn,leftm,leftn});
                mini[i][j]=min({topm,topn,leftm,leftn});
            }
        }
        long long mod = 1e9 + 7;
        if (maxi[n-1][m-1] < 0) return -1;    
        return maxi[n-1][m-1] % mod;
    }
};
