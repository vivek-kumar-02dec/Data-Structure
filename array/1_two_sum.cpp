class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int seen=nums[i]-target;
            if(mp.count(seen)) return {mp[seen],i};
            else mp[nums[i]]=i;
        }
        return {};
    }
};
