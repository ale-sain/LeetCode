class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> map;
        int dist = 0;
        int maxx = 0;
        for (int i = 0 ; i < nums.size() ; i++)
            map[nums[i]] = true;
        for (int i = 0 ; i < nums.size() ; i++){
            if (map.count(nums[i] - 1))
                map[nums[i]] = false;
        }
        for (int i = 0 ; i < nums.size() ; i++){
            if (map.count(nums[i]) && map[nums[i]] == true){
                for (int j = 0 ; map.count(nums[i] + j) ; j++)
                    dist++;
            }
            maxx = max(dist, maxx);
            dist = 0;
        }
        return maxx;
    }
};