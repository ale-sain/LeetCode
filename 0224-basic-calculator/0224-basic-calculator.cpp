class Solution {
public:
    int calculate(string s) {
        int nb = 0;
        int pos = 0;
        stack<bool> state({false});
        string nbS = "";

        for (int i = 0 ; i < s.size() ; i++)
        {
            if (s[i] == '(')
                state.push(pos < 0 ? true : false);
            else if (s[i] == ')')
                state.pop();  
            else if (isdigit(s[i]))
            {
                while (i < s.size() && isdigit(s[i]))
                    nbS += s[i++];
                nb = (pos < 0 ? nb - stoi(nbS) : nb + stoi(nbS));
                nbS = "";
                if (i != s.size())
                    i--;
            }
            else if (s[i] == '+' || s[i] == '-')
                pos = (s[i] == '+' ? (state.top() ? -1 : 1) : (state.top() ? 1 : -1));
        }
        return nb;
    }
};