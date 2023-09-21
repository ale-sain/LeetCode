class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int mark, sum = 0;
        int worst = INT_MAX;
        for (int i = 0 ; i < gas.size() ; i++)
        {
            sum += gas[i] - cost[i];
            if (sum <= worst)
            {
                worst = sum;
                mark = (i == gas.size() - 1 ? 0 : i + 1);
            }
        }
        return (sum < 0 ? -1 : mark);
    }
};