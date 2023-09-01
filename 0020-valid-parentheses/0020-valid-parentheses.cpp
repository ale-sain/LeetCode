class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (int i = 0 ; i < s.size() ; i++)
        {
            switch (s[i])
            {
                case ')':
                    if (stack.size() == 0 || stack.top() != '(')
                        return false;
                    stack.pop();
                    break;
                case ']':
                    if (stack.size() == 0 || stack.top() != '[')
                        return false;
                    stack.pop();
                    break;
                case '}':
                    if (stack.size() == 0 || stack.top() != '{')
                        return false;
                    stack.pop();
                    break;
                default:
                    stack.push(s[i]);
            }
        }
        if (stack.size() != 0)
            return false;
        return true;
    }
};