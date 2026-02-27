class Solution {
public:
    unordered_map<int,int> mp;
    int idx;
    TreeNode* build(vector<int> postorder,int st,int end){
        if(st>end) return NULL;
        int val=postorder[idx--];
        int mid=mp[val];
        TreeNode* root=new TreeNode(val);
        root->right=build(postorder,mid+1,end);
        root->left=build(postorder,st,mid-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        idx=n-1;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return build(postorder,0,n-1);
    }
};
