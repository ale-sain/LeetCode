class Solution {
public:
    bool canJump(vector<int>& nums) {
        int prec, k = nums.size() - 1;
        for (prec = k - 1 ; prec >= 0 ; prec--)
        {
            if (prec >= k - nums[prec])
                k = prec;
        }
        return (k == 0);
    }
};