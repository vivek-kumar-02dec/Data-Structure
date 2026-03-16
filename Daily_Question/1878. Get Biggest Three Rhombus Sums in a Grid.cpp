class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set<int> st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                st.insert(grid[i][j]);
                for(int node=1; ;node++){
                    // int r=i+2*node;
                    // int left=i-node;
                    // int right=i+node;

                    if(i+2*node>=n || j-node<0 || j+node>=m) break;
                    int sum=0;
                    int x=i;
                    int y=j;
                    for(int k=0;k<node;k++){
                        sum+=grid[x+k][y+k];
                    }
                    for(int k=0;k<node;k++){
                        sum+=grid[x+node+k][y+node-k];
                    }
                    for(int k=0;k<node;k++){
                        sum+=grid[x+2*node-k][y-k];
                    }
                    for(int k=0;k<node;k++){
                        sum+=grid[x-k+node][y+k-node];
                    }
                    st.insert(sum);
                }
            }
        }
    vector<int> ans;
        for(auto it=st.rbegin();it!=st.rend() && ans.size()<3;++it){
            ans.push_back(*it);
        }
        return ans;
    }
};
