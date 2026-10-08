class Solution {
private:
    void findSubset(vector<int> &nums,vector<vector<int>> &ans,vector<int> &store,int index,int n){
        
            ans.push_back(store);
        

        for(int i=index;i<n;i++){
            if(i>index&&nums[i-1]==nums[i])
                continue;

            store.push_back(nums[i]);
            findSubset(nums,ans,store,i+1,n);
            store.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> store;
        int index=0;
        sort(nums.begin(),nums.end());
        findSubset(nums,ans,store,index,n);
        return ans;
    }
};