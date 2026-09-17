class Solution {
public:
    bool checkValid(int row , int col , vector<vector<char>>& board){
        int n = board.size();
        //check row
        for(int i = 0 ; i<n ; i++){
            if(i == col || board[row][i] == '.') continue;
            if(board[row][i] == board[row][col]) return false;
        }

        for(int i = 0 ; i<n ; i++){
            if(i == row || board[i][col] == '.') continue;
            if(board[i][col] == board[row][col]) return false;
        }

        //check block
        int sr = (row/3)*3;
        int sc = (col/3)*3;

        for(int i = sr ; i<sr+3 ; i++){
            for(int j = sc ; j<sc+3 ; j++){
                if((i == row && j == col) || (board[i][j] == '.'))
                    continue;
                
                if(board[i][j] == board[row][col]) return false;
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        //check each valid cell
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                if(!checkValid(i,j,board)) return false;
            }
        }

        return true;
    }
};
