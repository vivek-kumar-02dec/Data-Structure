class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<pair<int,int>>> pre(n+1,vector<pair<int,int>>(m+1,{0,0}));
        int count=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int x=pre[i-1][j].first+pre[i][j-1].first-pre[i-1][j-1].first;
                int y=pre[i-1][j].second+pre[i][j-1].second-pre[i-1][j-1].second;
                if(grid[i-1][j-1]=='X') x++;
                else if (grid[i-1][j-1]=='Y') y++;

                if(x==y && x>0) count++;
                pre[i][j]={x,y};
            }
        }
        return count;
    }
};
