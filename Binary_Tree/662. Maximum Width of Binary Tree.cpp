class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        long long width = 1;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            int n = q.size();
            long long f = q.front().second;
            long long b = q.back().second;
            width = max(width, b - f + 1);
            for (int i = 0; i < n; i++) {
                auto [node, idx] = q.front();
                idx-=f;
                q.pop();
                if (node->left)
                    q.push({node->left, 2LL* idx + 1});
                if (node->right)
                    q.push({node->right, 2LL * idx + 2});
            }
        }
        return (int)width;
    }
};
