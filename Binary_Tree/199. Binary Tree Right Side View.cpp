class Solution {
public:
    map<int,int>mp;
    void solve(TreeNode* root,int idx){
        if(!root) return;
        mp[idx]=root->val;
        solve(root->left,idx+1);
        solve(root->right,idx+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root,0);
        for(auto &it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
