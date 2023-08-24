class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;
        for (int i = 0 ; i < ransomNote.size() ; i++)
            map[ransomNote[i]]++;
        for (int i = 0 ; i < magazine.size() ; i++){
            if (map.count(magazine[i]))
                map[magazine[i]]--;
        }
        for (const auto &pair : map){
            if (pair.second > 0)
                return false;
        }
        return true;
    }
};