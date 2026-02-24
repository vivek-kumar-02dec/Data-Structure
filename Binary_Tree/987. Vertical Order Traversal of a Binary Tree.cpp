
class Solution {
public:
    map<int, map<int, multiset<int>>> mp;
    void solve(TreeNode* root, int left, int right) {
        if (!root)
            return;
        mp[right][left].insert(root->val);
        solve(root->left, left +1, right - 1);
        solve(root->right, left + 1, right + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        solve(root, 0, 0);
        for (auto& x : mp) {
            vector<int> temp;
            for (auto& it : x.second) {
                temp.insert(temp.end(), it.second.begin(), it.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
