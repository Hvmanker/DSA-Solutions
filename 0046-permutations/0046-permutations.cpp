class Solution {
private:
    void permutate(vector<int>& nums, vector<vector<int>>& ans,
                   vector<int>& op, vector<bool>& used) {
        if (op.size() == nums.size()) {
            ans.push_back(op);
            return;
        }

        for (int x = 0; x < nums.size(); x++) {
            if (used[x]) continue;

            used[x] = true;
            op.push_back(nums[x]);

            permutate(nums, ans, op, used);

            op.pop_back();
            used[x] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> op;
        vector<bool> used(nums.size(), false);

        permutate(nums, ans, op, used);

        return ans;
    }
};