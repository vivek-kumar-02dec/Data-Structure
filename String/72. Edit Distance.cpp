class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> nums(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++) nums[i][0]=i;
        for(int i=0;i<=n;i++) nums[0][i]=i;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]) nums[i][j]=nums[i-1][j-1];
                else{
                    nums[i][j]=1+min({
                        nums[i-1][j],
                        nums[i][j-1],
                        nums[i-1][j-1]
                    });
                }
            }
        }
        return nums[m][n];

    }
};
