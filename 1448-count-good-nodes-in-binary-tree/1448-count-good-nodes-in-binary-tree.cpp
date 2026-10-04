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
    void getCount(TreeNode* root,int maxVal,int &count){
        if(!root)
        {
            return;
        }
        if(root->val>=maxVal){
            count++;
            maxVal=root->val;
        }
        getCount(root->left,maxVal,count);
        getCount(root->right,maxVal,count);
    }
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        if(!root){
            return 0;
        }
        getCount(root,root->val,count);
        return count;
    }
};