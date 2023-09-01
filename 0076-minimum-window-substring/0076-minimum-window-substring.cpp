class Solution {

public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mapT, mapS;
        vector<pair<char, int>> vecS;
        string valid = "";
        int invisible = 0;
        int oldleft, right, left = 0;
        int iV = 0;
        int l = 0;
        int greatL = t.size();
        int minSize = 2147483647;
        string str = "";
        for (int i = 0 ; i < t.size() ; i++)
            mapT[t[i]]++;
        for (int right = 0 ; right < s.size() ; right++)
        {
            if (l < greatL) // build the word
            {
                if (mapT.count(s[right])) // if letter of s is in t
                {
                    mapS[s[right]]++; // store nb occurences in s to compare to required nb in t
                    vecS.push_back(make_pair(s[right], right - invisible)); // vec[order] : first -> char, second -> index in s
                }
                if (vecS.size())
                    str += s[right];
                else
                    invisible++;
                if (mapT.count(s[right]) && mapS[s[right]] <= mapT[s[right]]) // under or equal : an occurence of t in s
                    l++;
            }
            
            if (l == greatL) // word is complete : all occurences founded
            {
                if (minSize > right - left + 1) // if length of word < min, become min and valid = current word
                {
                    valid = str;
                    minSize = right - left + 1;
                }
                if (t.size() == 1)
                    break;
                oldleft = left;
                left = vecS[++iV].second; // return last next valid letter index to set left with
                char c = vecS[iV - 1].first; // target valid letter before lnvl that go out of the window
                mapS[c]--; // remove it from mapS
                if (mapS[c] < mapT[c])
                    l--;
                str.erase(0, left - oldleft);
            }
            if (l == greatL)
                right--;
        }
        return valid;
    }
};