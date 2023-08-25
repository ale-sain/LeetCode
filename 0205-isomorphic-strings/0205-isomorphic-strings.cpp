class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;
        for (int i = 0 ; i < s.size() ; i++){
            mapS[s[i]] += i;
            mapT[t[i]] += i;
            if (i > 0){
                if ((s[i] == s[i - 1] && t[i] != t[i - 1]) || (s[i] != s[i - 1] && t[i] == t[i - 1]))
                    return false;
            }
            if (mapS[s[i]] != mapT[t[i]])
                return false;
        }
        return true;
    }
};