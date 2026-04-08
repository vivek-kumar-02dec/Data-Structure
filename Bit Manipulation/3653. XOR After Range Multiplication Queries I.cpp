class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long mod=1000000007;
        for(auto it:queries){
            int idx=it[0];
            while(idx<=it[1]){
                nums[idx]=(1LL*nums[idx]*it[3])%mod;
                idx+=it[2];
            }
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans^=nums[i];
        }
        return ans;
    }
};
