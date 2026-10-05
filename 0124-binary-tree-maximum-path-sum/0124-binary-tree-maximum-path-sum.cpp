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
private:
    int helper(TreeNode* root,int &maxGain){
        if(!root)
            return 0;
        
        
        int leftSum = max(0,helper(root->left,maxGain));
        
        int rightSum = max(0,helper(root->right,maxGain));
        maxGain = max(maxGain,(leftSum+rightSum)+root->val);
        return root->val+max(leftSum,rightSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root){
            return 0;
        }
        int maxGain =root->val;
        helper(root,maxGain);
        return maxGain;

    }
};