class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int flag = 0;
        for (int i = 1 ; i < nums.size() ; i++)
        {
            if (nums[k] != nums[i])
            {
                nums[++k] = nums[i];
                flag = 0;
            }
            else if (!flag)
            {
                nums[++k] = nums[i];
                flag++;
            }
        }
        return (k + 1);
    }
};