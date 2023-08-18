class Solution {
public:
    int longestPalindrome(string s) {
         char a;
        int nb = 1;
        int length = 0;
        int flag = 0;
        for (int i = 0; i < s.size() ; i++)
        {
            a = s[i];
            for (int j = i + 1 ; j < s.size() ; j++)
            {
                if (s[j] == a && s[j] != 0)
                {
                    nb++;
                    s[j] = 0;
                }
            }
            if (nb > 1)
            {
                if (nb % 2 == 0)
                    length += nb;
                else if (!flag)
                {
                    length += nb;
                    flag = 1;
                }
                else
                    length += nb - 1;
            }
            else if (!flag && s[i] != 0)
            {
                length += 1;
                flag = 1;
            }
            nb = 1;
        }
        return (length);
    }
};