class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> map;
        vector<vector<int>> ans;
        set<vector<int>> s;
        int start = 0;
        int zero = 0;
    
        std::sort(nums.begin(), nums.end());
        for (int i = 0 ; i < nums.size() ; i++)
        { 
            if (i != 0 && i != nums.size() - 1)
                map[nums[i]] = i;
            if (nums[i] == 0)
                zero++;
        }
        if (zero >= 3)
            ans.push_back({0, 0, 0});
        for (int end = nums.size() - 1 ; end > start && nums[end] > 0 ; end--)
        {
            for (; start < end && nums[start] < 0 ; start++)
            {
                int k = (nums[start] + nums[end]) * -1;
                if (map.count(k))
                {
                    if (map[k] == start)
                    {
                        if (nums[start + 1] == nums[start])
                            map[k] = start + 1;
                    }
                    if (map[k] == end)
                    {
                        if (nums[end - 1] == nums[end])
                            map[k] = end - 1;
                    }
                    if (map[k] > start 
                        && map[k] < end 
                        && s.find({nums[start], nums[map[k]], nums[end]}) == s.end())
                    {
                        ans.push_back({nums[start], nums[map[k]], nums[end]});
                        s.insert({nums[start], nums[map[k]], nums[end]});
                    }
                }
            }
            start = 0;
        }
        return ans;
    }
};