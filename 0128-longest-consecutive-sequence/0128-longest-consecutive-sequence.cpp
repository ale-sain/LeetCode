class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxx = 1;
        int dist = 0;
        if (!nums.size())
            return 0;
        for (int i = 0 ; i < nums.size() - 1 ; i++)
        {
            while (i < nums.size() - 1 && nums[i + 1] - nums[i] <= 1)
            {
                if (nums[i] != nums[i + 1])
                    dist++;
                i++;
            }
            maxx = max(maxx, dist + 1);
            dist = 0;
        }
        return maxx;
    }
};