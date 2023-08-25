class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> curr;
        unordered_map<string, bool> used;
        istringstream iss(s);
        string str;
        for (int i = 0 ; i < pattern.size() ; i++){
            iss >> str;
            if (curr.count(pattern[i])){
                if (curr[pattern[i]] != str)
                    return false;
            }
            else{
                if (used[str])
                    return false;
                curr[pattern[i]] = str;
                used[str] = true;
            }
        }
        if (iss >> str)
            return false;
        return true;
    }
};