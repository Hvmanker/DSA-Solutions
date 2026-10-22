class Solution {
private:
    void findCombinations(vector<string> &letters,string digits,vector<string> &ans,string &store,int index){
        if(index==digits.length()){
            if(store.length()>0){
                ans.push_back(store);
            }
            
            return ;
        }
        int digit = digits[index]-'0';
        string letter = letters[digit];
        for(int i=0;i<letter.length();i++){
            store.push_back(letter[i]);
            findCombinations(letters,digits,ans,store,index+1);
            store.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> letters={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index =0;
        vector<string>ans;
        string store="";
        findCombinations(letters,digits,ans,store,index);
        return ans;
    }
};