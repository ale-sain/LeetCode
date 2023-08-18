class Solution {
public:
    int strStr(string haystack, string needle) {
        int pos = haystack.find(needle, 0);
        return (pos != std::string::npos ? pos : -1);
    }
};