# define DEAD 0
# define LIVING 1

class Solution {
private:
    void recursion(std::vector<std::vector<int>>& board, int i, int j)
    {
        int m = board.size(), n = board[0].size(), livingC = 0, futureState;
        if (j >= n)
        {
            i++;
            j = 0;
        }
        if (i >= m)
            return ;
        for (int row = i - 1 ; row <= i + 1 ; row++){
            for (int col = j - 1 ; col  <= j + 1 ; col++){
                if (col >= 0 && col < n && row >= 0 && row < m && board[row][col] == LIVING){
                    if (!(col == j && row == i))
                        livingC++;
                }
            }
        }
        futureState = (livingC == 2 || livingC == 3 ? (livingC == 3 && board[i][j] == DEAD ? LIVING : board[i][j]) : board[i][j] == LIVING ? DEAD : board[i][j]);
        recursion(board, i, j + 1);
        board[i][j] = futureState;
    }

public:
    void gameOfLife(std::vector<std::vector<int>>& board) 
    {
        recursion(board, 0, 0);
    }
};