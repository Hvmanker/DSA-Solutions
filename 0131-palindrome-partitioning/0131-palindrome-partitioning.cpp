class Solution {
private:
    bool isPalindrome(string& s, int start, int end) {
    while(start < end) {
        if(s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

    void findPalindrome(string s,vector<vector<string>> &ans,vector<string> &op,int index){
        if(index==s.length()){
            ans.push_back(op);
            return;
        }

        for(int i=index;i<s.length();i++){
            if(isPalindrome(s,index,i)){
                op.push_back(s.substr(index,i-index+1));
                findPalindrome(s,ans,op,i+1);
                op.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> op;
        int index=0;
        findPalindrome(s,ans,op,index);
        return ans;
    }
};