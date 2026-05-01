class Solution {
public:
    vector<int> col;
    vector<int> dig1;
    vector<int> dig2;
    int count=0;
    void solve(int n,int row){
        if(row==n){
            count++;
            return;
        }
        for(int c=0;c<n;c++){
            if(col[c] || dig1[c+row] || dig2[c-row+n-1]) continue;
            col[c]=dig1[c+row]=dig2[c-row+n-1]=1;
            solve(n,row+1);
            col[c]=dig1[c+row]=dig2[c-row+n-1]=0;
        }
    }
    int totalNQueens(int n) {
        col.assign(n,0);
        dig1.assign(2*n,0);
        dig2.assign(2*n,0);
        solve(n,0);
        return count;
    }
};
