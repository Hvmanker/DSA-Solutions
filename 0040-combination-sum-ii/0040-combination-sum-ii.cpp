class Solution {
private:
 void findSum(vector<int> &candidates,int target,vector<vector<int>> &ans,vector<int>&store,int index){
            if(target==0){
                ans.push_back(store);
                 return;
            }
           
    
        
        for(int i=index;i<candidates.size();i++){
             if (i > index && candidates[i] == candidates[i - 1]) continue;

            if(candidates[i]>target){
                break;
            }

            store.push_back(candidates[i]);
            findSum(candidates,target-candidates[i],ans,store,i+1);
            store.pop_back();
        }
        // //exclude
        // findSum(candidates,target,ans,store,index+1);

        // //include
        
        // if(candidates[index]<=target){
        //     target=target-candidates[index];
        //     store.push_back(candidates[index]);
        //     findSum(candidates,target,ans,store,index+1);
        // }
        
        
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> store;
        int index=0;
        sort(candidates.begin(),candidates.end());
        findSum(candidates,target,ans,store,index);
        return ans;
    }
};