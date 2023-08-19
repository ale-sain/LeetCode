class Solution {
    private:
            void recursion(std::vector<std::vector<int>> &matrix, int pos)
            {
                int n = matrix[0].size();
                int m = matrix.size();
                if (pos == m * n)
                    return ;
                while (pos < m * n - 1 && matrix[pos / n][pos % n] != 0)
                    pos++;
                if (matrix[pos / n][pos % n] == 0)
                {
                    recursion(matrix, pos + 1);
                    for (int line = 0 ; line < m ; line++)
                        matrix[line][pos % n] = 0;
                    for (int col = 0 ; col < n ; col++)
                        matrix[pos / n][col] = 0;
                }
            }

    public:
            void setZeroes(vector<vector<int>>& matrix) {
                recursion(matrix, 0);
        }
};