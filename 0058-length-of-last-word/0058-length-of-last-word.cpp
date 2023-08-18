class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int res = 0;
        while (s[i] == ' ')
            i--;
        while (i >= 0 && isalpha(s[i--]))
            res++;
        return res;
    }
};