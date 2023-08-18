class Solution {
public:
    int romanToInt(string s) 
    {
        int res = 0;
        std::unordered_map<char, int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        for (int i = 0 ; i < s.size() ; i++)
        {
            if (map[s[i]] >= map[s[i + 1]])
                res += map[s[i]];
            else
                res += map[s[i + 1]] - map[s[i++]];
        }
        return res;
    }
};