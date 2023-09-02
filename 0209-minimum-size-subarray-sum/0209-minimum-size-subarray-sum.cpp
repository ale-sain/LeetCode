class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i, j, sumW = 0;
        int sizeW = 0;
        int previousSum = 0;
        for (i = 0 ; i < nums.size() && sumW < target ; i++)
        {
            sumW += nums[i];
            sizeW++;
        }
        if (sumW < target)
            return 0;
        for (i = 0 ; i + sizeW - 1 < nums.size(); i++)
        {
            if (i != 0)
                sumW = sumW - nums[i - 1] + nums[i + sizeW - 1];
            for (j = i ; (j < i + sizeW) && (sumW - nums[j] >= target) ; j++)
                sumW -= nums[j];
            sizeW -= (j - i);
            i = j;
        }
        return sizeW;
    }
};