class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int minn, arrow = 0;
        sort(points.begin(), points.end());
        for (int i = 0 ; i < points.size(); i++)
        {
            minn = points[i][1];
            for ( ; i < points.size() - 1 && points[i + 1][0] <= minn ; i++)
                minn = min(minn, points[i + 1][1]);
            arrow++;
        }
        return arrow;
    }
};