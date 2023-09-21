class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int length, water = 0;
        int h = INT_MAX;
        for (int start = 0, end = n - 1 ; start < end ;)
        {
            length = end - start;
            h = min(height[start], height[end]);
            water = max(length * h, water);
            if (h == height[start])
                start++;
            else
                end--;
        }
        return water;
    }
};