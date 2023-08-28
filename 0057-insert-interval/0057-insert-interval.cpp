class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int start, end;
        int exist = false;
        if (!intervals.size())
        {
            ans.push_back(newInterval);
            return ans;
        }
        for (int i = 0 ; i < intervals.size() ; i++)
        {
            if (newInterval[0] >= intervals[i][0] && ((i < intervals.size() - 1 && newInterval[0] <= intervals[i + 1][0])
                || (i == intervals.size() - 1)))
            {
                intervals.insert(intervals.begin() + (i + 1), newInterval);
                exist = true;
                break;
            }
        }
        if (!exist)
            intervals.insert(intervals.begin(), newInterval);
        for (int i = 0 ; i < intervals.size() ; i++)
        {
            start = intervals[i][0];
            end = intervals[i][1];
            while (i < intervals.size() -1 && end >= intervals[i + 1][0])
            {
                end = max(end, intervals[i + 1][1]);
                i++;
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};