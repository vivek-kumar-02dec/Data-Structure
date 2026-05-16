class Solution {
public:
    int numTrees(int n) {
        vector<int> num(n+1,1);
        for(int i=2;i<=n;i++){
            int t=0;
            for(int j=1;j<=i;j++){
                t+=num[j-1]*num[i-j];
            }
            num[i]=t;
        }
        return num[n];
    }
};
