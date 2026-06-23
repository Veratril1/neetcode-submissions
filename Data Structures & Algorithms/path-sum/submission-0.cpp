/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int fl = 0;
    void dfs(TreeNode* root,int k){
        if(!root)return;
        if(!root->left && !root->right){
            if(k==root->val)fl=1;
            return;
        }
        dfs(root->left,k-root->val);
        dfs(root->right,k-root->val);
    }
    bool hasPathSum(TreeNode* root, int k) {
        dfs(root,k);
        return fl;
    }
};