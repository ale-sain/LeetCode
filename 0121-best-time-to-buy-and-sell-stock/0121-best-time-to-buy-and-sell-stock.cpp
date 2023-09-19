class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int buy = 0, sell = 1; sell < prices.size(); buy++, sell++) 
        {
            mini = min(prices[buy], mini);
            maxi = max (prices[sell] - mini, maxi);
        }
        return (maxi > 0 ? maxi : 0);
    }
};