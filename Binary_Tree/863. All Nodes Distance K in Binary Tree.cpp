class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;
        queue<TreeNode*> q;
        parents[root] = NULL;
        q.push(root);
        // adding parents
        while (!q.empty()) {
            TreeNode* nd = q.front();
            q.pop();
            if (nd->left) {
                parents[nd->left] = nd;
                q.push(nd->left);
            }
            if (nd->right) {
                parents[nd->right] = nd;
                q.push(nd->right);
            }
        }
        unordered_set<TreeNode*> vis;
        q.push(target);
        vis.insert(target);
        // traverse upto k length
        while (k-- && !q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left && !vis.count(temp->left)) {
                    vis.insert(temp->left);
                    q.push(temp->left);
                }
                if (temp->right && !vis.count(temp->right)) {
                    vis.insert(temp->right);
                    q.push(temp->right);
                }
                if (parents[temp] && !vis.count(parents[temp])) {
                    vis.insert(parents[temp]);
                    q.push(parents[temp]);
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
