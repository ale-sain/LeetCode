class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int prefix = 1;
        std::string res = "";
        int i = 0;
        int count = 0;
        
        for (int j = 0 ; j < strs[i].size() ; j++)
        {
            prefix = 1;
            for (i = 0 ; i < strs.size() - 1 ; i++)
            {
                if (j < strs[i].size() && j < strs[i + 1].size())
                {
                    if (strs[i][j] == strs[i + 1][j])
                        prefix++;
                }
            }
            if (prefix == strs.size() && j == count)
            {
                count++;
                res += strs[i][j];
            }
        }
        return res;
    }
};