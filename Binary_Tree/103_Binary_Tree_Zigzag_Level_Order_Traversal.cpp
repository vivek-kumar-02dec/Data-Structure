class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector < vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front();
                q.pop();
                int x = curr->val;
                temp.push_back(x);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            ans.push_back(temp);
        }
        int s = ans.size();
        for (int i = 0; i < s; i++) {
            if (i % 2 == 0)
                continue;
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
