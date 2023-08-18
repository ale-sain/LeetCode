class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<char, int> map;
        for (int i = 0 ; i < 9 ; i++)
        {
            for (int j = 0 ; j < 9 ; j++)
            {
                if (board[i][j] != '.')
                    map[board[i][j]]++;
                if (map[board[i][j]] > 1)
                    return false;
            }
            map.clear();
        }
        for (int j = 0 ; j < 9 ; j++)
        {
            for (int i = 0 ; i < 9 ; i++)
            {
                if (board[i][j] != '.')
                    map[board[i][j]]++;
                if (map[board[i][j]] > 1)
                    return false;
            }
            map.clear();
        }
        for (int i = 0 ; i < 9 ; i += 3)
        {
            for (int j = 0 ; j < 9 ; j += 3)
            {
                for (int a = 0 ; a < 3 ; a++)
                {
                    for (int e = 0 ; e < 3 ; e++)
                    {
                        if (board[i + a][j + e] != '.')
                            map[board[i + a][j + e]]++;
                        if (map[board[i + a][j + e]] > 1)
                            return false;
                    }
                }
                map.clear();
            }
        }
        return true;
    }
};