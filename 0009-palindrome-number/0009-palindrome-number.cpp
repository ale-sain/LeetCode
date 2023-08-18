class Solution {
public:
    bool isPalindrome(int x) {
        std::ostringstream oss;
        oss << x;
        string str = oss.str();
        for (int i = 0 ; i < str.size() ; i++)
        {
            if (str[i] != str[str.size() - 1 - i])
                return false;
        }
        return true;
    }
};