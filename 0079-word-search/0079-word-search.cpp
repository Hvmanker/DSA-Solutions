class Solution {
public:
    void findWord(vector<vector<char>> &board,string word,bool &ans,int start,int row,int col){
        if(start==word.size()){
            ans=true;
            return ;
        }
        if(row==board.size()&&col==board[row].size()){
            return;
        }
        char character = board[row][col];
        board[row][col]='#';
        //left
        if(col-1>=0&&board[row][col-1]==word[start]){
            findWord(board,word,ans,start+1,row,col-1);
        }
        //up
        if(row-1>=0&&board[row-1][col]==word[start]){
            findWord(board,word,ans,start+1,row-1,col);
        }
        //right
        if(col+1<board[row].size()&&board[row][col+1]==word[start]){
            findWord(board,word,ans,start+1,row,col+1);
        }
        //down
        if(row+1<board.size()&&board[row+1][col]==word[start]){
            findWord(board,word,ans,start+1,row+1,col);
        }
        board[row][col]=character;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        int start=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[start]){
                    findWord(board,word,ans,start+1,i,j);
                    if(ans==true){
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};