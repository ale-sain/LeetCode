class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i, j, k = 0;
        vector<int> tmp;
        for (i = 0, j = 0; i < m && j < n ; k++)
        {
            tmp.push_back(nums1[i] < nums2[j] ? nums1[i++] : nums2[j++]);
        }
        while (k < (m + n))
        {
            tmp.push_back(i == m ? nums2[j++] : nums1[i++]);
            k++;
        }
        for (int a = 0 ; a < tmp.size() ; a++)
        {
            nums1[a] = tmp[a];
        }
    }
};