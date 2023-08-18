class Solution {
public:
    bool isPalindrome(string s) {
        std::string str = "";
        for (int i = 0 ; i < s.size() ; i++)
        {
            if (std::isalnum(s[i]))
                str += (std::isupper(s[i]) ? std::tolower(s[i]) : s[i]);
        }
        if (str.size() == 0 || str.size() == 1)
            return true;
        int j = str.size() - 1;
        for (int i = 0 ; i <= j ; i++)
        {
            if (str[i] != str[j])
                return false;
            j--;
        }
        return true;
    }
};