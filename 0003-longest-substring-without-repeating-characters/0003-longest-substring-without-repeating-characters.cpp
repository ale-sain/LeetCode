class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int j, k = 0;
        int prev;
        int continu = false;
        unordered_map<char, int> map;
        for (int i = 0 ; i < s.size() && !map.count(s[i]) ; i++)
        {
            map[s[i]]++;
            k++;
        }

        for (int i = 1 ; i + k  < s.size(); i++)
        {
            continu = false;
            map[s[i - 1]]--;
            map[s[i + k - 1]]++;
            for (const auto &pair : map) {
                if (pair.second > 1) {
                    continu = true;
                    break;
                }
            }
            if (continu)
                continue;
            for (j = i + k ; j < s.size() ; j++)
            {
                if (map[s[j]])
                    break;
                map[s[j]]++;
                k++;
            }
        }
        return k;
    }
};