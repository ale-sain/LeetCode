class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> vec;
        string ans = "";
        int j;
        for (int i = 0 ; i < nums.size() ; i++)
        {
            for (j = i ; j < nums.size() - 1 && std::abs((long)nums[j + 1] - (long)nums[j]) == 1 ; j++) {}
            if (i == j)
                ans += to_string(nums[i]);
            else
                ans += to_string(nums[i]) + "->" + to_string(nums[j]);
            i = j;
            vec.push_back(ans);
            ans = "";
        }
        return vec;
    }
};