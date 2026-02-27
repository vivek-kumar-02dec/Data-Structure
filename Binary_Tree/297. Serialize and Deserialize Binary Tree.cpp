class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "#";
        string str;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* n = q.front();
            q.pop();
            if (!n) {
                str += "#,";
                continue;
            }
            str += to_string(n->val) + ",";
            q.push(n->left);
            q.push(n->right);
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "#")
            return NULL;
        string str;
        vector<string> temp;
        for (char it : data) {
            if (it == ',') {
                temp.push_back(str);
                str.erase();
            } else
                str.push_back(it);
        }
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(temp[0]));
        q.push(root);
        int n = temp.size();
        int i = 1;
        while (i < n && !q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (i < n && temp[i] != "#") {
                node->left = new TreeNode(stoi(temp[i]));
                q.push(node->left);
            }
            i++;
            if (i < n && temp[i] != "#") {
                node->right = new TreeNode(stoi(temp[i]));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};
