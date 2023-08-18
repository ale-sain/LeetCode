class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        int sizeT = numRows + (numRows - 2);
        string tmp = "";
        int j;
        if (numRows == s.size())
            return s;
        for (int i = 0 ; i < numRows ; i++)
        {
            for (j = i ; j <= s.size() + 2 * i; j += sizeT)
            {
                if (i != j && i != 0 && i != numRows - 1 && (j - 2 * i < s.size()))
                    tmp += s[j - 2 * i];
                if (j < s.size())
                    tmp += s[j];
            }    
        }
        return tmp;
    }
};