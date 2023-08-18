class Solution {
public:
    string reverseWords(string s) {
        std::istringstream iss(s);
        std::vector<string> v;
        std::string word;
        while (iss >> word)
        {
            v.push_back(word);
            v.push_back(" ");
        }
        word = "";
        for (int i = v.size() - 2 ; i >= 0 ; i--)
            word += v[i];
        return word;
    }
};