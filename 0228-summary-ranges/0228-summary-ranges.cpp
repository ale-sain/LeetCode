class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> vec;
        int j;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            for (j = i ; j < nums.size() - 1 && std::abs((long)nums[j + 1] - (long)nums[j]) == 1 ; j++) {}
            if (i == j)
                vec.push_back(to_string(nums[i]));
            else
                vec.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
            i = j;
        }
        return vec;
    }
};