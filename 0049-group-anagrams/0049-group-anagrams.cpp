class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> map;
        vector<vector<string>> vec;
        string str;
        for (int i = 0 ; i < strs.size() ; i++)
        {
            str = strs[i];
            sort(str.begin(), str.end());
            if (map.count(str)) 
                vec[map[str]].push_back(strs[i]);
            else{
                map[str] = vec.size();
                vec.push_back({strs[i]});
            }
        }
        return vec;
    }
};