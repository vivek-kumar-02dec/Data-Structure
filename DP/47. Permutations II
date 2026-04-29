class Solution {
public:
    void solve(vector<int> nums, vector<int>& temp, vector<vector<int>>& ans,
               vector<bool>& vis) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (vis[i])
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])
                continue;
            temp.push_back(nums[i]);
            vis[i] = true;
            solve(nums, temp, ans, vis);
            temp.pop_back();
            vis[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> vis(nums.size(), false);
        solve(nums, temp, ans, vis);
        return ans;
    }
};
