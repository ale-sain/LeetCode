class Solution {
public:
    int jump(vector<int>& nums) {
        int farest, reach = nums.size() - 1;
        int count = 0;
        for (int nearest = reach ; reach > 0 ; count++)
        {
            for (int i = reach - 1 ; i >= 0 ; i--)
            {
                if (nums[i] >= reach - i)
                   nearest = min(nearest, i);
            }
            reach = nearest;
        }
        return count;
    }
};