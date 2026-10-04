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
    int kthSmallest(TreeNode* root, int &k) {
        if(!root){
            return INT_MAX;
        }

        int leftAns = kthSmallest(root->left,k);
        if(leftAns!=INT_MAX){
            return leftAns;
        }

        k--;
        if(k==0){
            k = INT_MAX;
            return root->val;
        }

        return kthSmallest(root->right,k);
    }
};