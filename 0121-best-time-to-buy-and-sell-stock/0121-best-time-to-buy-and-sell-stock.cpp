class Solution {
public:
    int maxProfit(vector<int>& prices) {
        std::unordered_map<int, int> map;
        if (prices.size() == 1)
            return 0;
        int min = 0;
        int max = 1;
        map[min] = prices[0];
        map[max] = prices[1];
        int diff = 0;
        if (max > min && (map[max] - map[min]) > diff)
                diff = map[max] - map[min];
        for (int i = 1 ; i < prices.size() - 1; i++)
        {
            if (map[min] > prices[i])
            {
                min = i;
                map[min] = prices[i];
                max = i + 1;
                map[max] = prices[i + 1];
            }
            if (map[max] < prices[i + 1])
            {
                max = i + 1;
                map[max] = prices[i + 1];
            }
            if (max > min && (map[max] - map[min]) > diff)
                diff = map[max] - map[min];
        }
        return diff;
    }
};