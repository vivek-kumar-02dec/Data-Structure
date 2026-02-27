class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        while (!q.empty()) {
            TreeNode* n = q.front();
            q.pop();
            if (n->left) {
                q.push(n->left);
                count++;
            }
            if (n->right) {
                q.push(n->right);
                count++;
            }
        }
        return count;
    }
};
