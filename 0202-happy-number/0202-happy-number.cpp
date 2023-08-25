class Solution {
public:
    bool isHappy(int n) {
        int res = 0;
        int rest = n;
        unordered_map<int, int> map;
        for (int j = 0 ; rest != 1 ; j++)
        {
            while (rest > 0)
            {
                res += pow(rest % 10, 2);
                rest = rest / 10;
            }
            rest = res;
            map[rest]++;
            if (map[rest] > 1)
                return false;
            res = 0;
        }
        return true;
    }
};