class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int j=0;j<k;j++){
            for(int i=0;i<k/2;i++){
                swap(grid[x+i][y+j],grid[x+k-1-i][y+j]);
            }
        }
        return grid;
    }
};
