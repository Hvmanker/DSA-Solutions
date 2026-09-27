class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }

        int left=0;
        int right=0;
        if(root->left){
           left= maxDepth(root->left);
        }
        if(root->right){
           right= maxDepth(root->right);
        }

        int maxLeftOrRight=max(left,right);
        return (maxLeftOrRight+1);

    }
};
