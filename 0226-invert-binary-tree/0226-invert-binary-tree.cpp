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
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr){
            return root;
        }
        if(!root->left&&!root->right){
            return root;
        }
        TreeNode* smallNodeLeft=nullptr;
        TreeNode* smallNodeRight=nullptr;
        if(root->left){
            smallNodeLeft=invertTree(root->left);
        }
        if(root->right){
            smallNodeRight=invertTree(root->right);
        }
        root->left=smallNodeRight;
        root->right=smallNodeLeft;
        return root;
        
    }
};
