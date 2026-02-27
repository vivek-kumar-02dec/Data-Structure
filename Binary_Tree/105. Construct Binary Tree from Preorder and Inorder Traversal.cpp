class Solution {
public:
    unordered_map<int, int> mp;
    int idx = 0;
    TreeNode* build(vector<int> pre, int st, int end) {
        if (st > end)
            return NULL;
        int val = pre[idx++];
        int mid = mp[val];
        TreeNode* root = new TreeNode(val);
        root->left = build(pre, st, mid - 1);
        root->right = build(pre, mid + 1, end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        return build(preorder, 0, n - 1);
    }
};
