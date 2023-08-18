class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         std::vector<int> res(matrix.size() * matrix[0].size());
        int e = 0, i = 0, j = 0, tour = 0;
        while (e < res.size())
        {
            // going right
            while (j < matrix[i].size() - tour && e < res.size()){
                if (j < matrix[i].size() - tour - 1 || e == res.size() - 1)
                    res[e++] = matrix[i][j];
                j++;
            }
            j--;
            // going down
            while (i < matrix.size() - tour && e < res.size()){
                if (i < matrix.size() - tour - 1)
                    res[e++] = matrix[i][j];
                i++;
            }
            i--;
            // going right
            while (j >= tour && e < res.size()){
                if (j >= tour + 1)
                    res[e++] = matrix[i][j];
                j--;
            }
            j++;
            tour++;
            // going up
            while (i >= tour && e < res.size()){
                if (i >= tour + 1)
                    res[e++] = matrix[i][j];
                i--;
            }
            i++;
        }
        return res;
    }
};