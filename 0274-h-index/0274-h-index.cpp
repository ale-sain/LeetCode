class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0;
        int paper = 1;
        sort(citations.begin(), citations.end());
        for (int i = citations.size() - 1 ; i >= 0 ; i--)
        {
            if (paper <= citations[i])
                h = max(h, paper);
            paper++;
        }
        return h;
    }
};