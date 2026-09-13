class Solution {
private:
    void generateValidParenthesis(int n,int open,int close,vector<string> &ans,string op){
        if(open==n&&close==n){
            ans.push_back(op);
            return;
        }

        if(open<n){
            generateValidParenthesis(n,open+1,close,ans,op+"(");
        }

        if(close<open){
            generateValidParenthesis(n,open,close+1,ans,op+")");
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        int open=0,close=0;
        vector<string> ans;
        string op;
        generateValidParenthesis(n,open,close,ans,op);
        return ans;
    }
};