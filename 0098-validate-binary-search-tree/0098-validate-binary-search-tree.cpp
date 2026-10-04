class Solution {
private:
    bool check(TreeNode* root, long long minVal, long long maxVal) {
        if (!root) {
            return true;
        }

        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }

        return check(root->left, minVal, root->val) &&
               check(root->right, root->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};
