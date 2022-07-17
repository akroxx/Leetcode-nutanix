class Solution {
public:
    bool isValid(vector< vector< char>> & board, int row, int col, char c){
        // //row check

        // for(int i = 0; i < 9; i++){
        //     if(board[i][col] == c)
        //         return false;
        // }

        // //col check

        // for(int i = 0; i < 9; i++){
        //     if(board[row][i] == c){
        //         return false;
        //     }
        // }

        // //box check
        // int x0 = (row/3) * 3, y0 = (col/3) * 3;
        // for(int i = 0; i < 3; i++){
        //     for(int j = 0; j < 3; j++){
        //         if(board[x0 + i][y0 + j] == c)
        //             return false;
        //     }
        // }

        for(int i = 0; i < 9; i++){
            //col check
            if(board[row][i] == c){
                return false;
            }

            //row check
            if(board[i][col] == c){
                return false;
            }

            //box check
            if(board[(row/3) * 3 + i/3][(col/3) * 3 + i%3] == c){
                return false;
            }
        }

        return true;

    }
    bool helper(vector< vector< char> > & board, int row, int col){
        //done
        if(row == 9){
            return true;
        }
        //time for next row
        if(col == 9){
            return helper(board, row+1, 0);
        }

        //already marked, go-to next column
        if(board[row][col] != '.'){
            return helper(board, row, col+1);
        }

        for(char c = '1'; c <= '9'; c++){
            if(isValid(board, row, col, c)){
                board[row][col] = c;
                //without return here, board reverts to initial state
                if(helper(board, row, col+1)){
                    return true;
                }
                //if true not returned then probably invalid, return to init state i.e. '.'
                board[row][col] = '.';
            }
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);
    }
};