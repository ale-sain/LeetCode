class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int res;
        std::unordered_map<int, int> map;
        for (int i = 0 ; i < nums.size() ; i++)
            map[nums[i]] = i;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            res = target - nums[i];
            if (map.count(res) && map[res] != i)
                return {map[res], i};
        }
        return {};
    }
};