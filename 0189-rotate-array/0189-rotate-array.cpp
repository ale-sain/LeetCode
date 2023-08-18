class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::vector<int> tmp(nums.size(), 0);
        k %= nums.size();
        for (int n = 0 ; n < nums.size() ; n++)
            tmp[n + k < nums.size() ? n + k : n + k - nums.size()] = nums[n];
        nums = tmp;
    }
};