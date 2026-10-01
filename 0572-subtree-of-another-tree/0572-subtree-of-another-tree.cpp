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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q){
            return true;
        }
        if(!p||!q){
            return false;
        }

        bool curAns= p->val==q->val;
        

        bool leftAns= isSameTree(p->left,q->left);
        bool rightAns = isSameTree(p->right,q->right);

        return (curAns&&leftAns&&rightAns);
        
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root){
            return false;
        }
        if(!subRoot){
            return true;
        }

        bool val=false;
        if(root->val==subRoot->val){
           val =isSameTree(root,subRoot);

        }

        if(val==true){
            return val;
        }
        bool leftVal = isSubtree(root->left,subRoot);
        bool rightVal = isSubtree(root->right,subRoot);
        return val||leftVal||rightVal; 

        
    }
};