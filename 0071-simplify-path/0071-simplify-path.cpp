class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        int poping = 0;
        size_t pos;
        int j;
        for (int i = path.size() - 1 ; i >= 0 ; i--)
        {
            if (path[i] == '/' && i + 1 != path.size()) 
            {
                switch (path[i + 1])
                {
                    case '/' :
                        break;
                    case '.' :
                        j = 0;
                        while (path[j + i + 1] == '.' && j + i + 1 != path.size())
                            j++;
                        if (j + i + 1 == path.size() || path[j + i + 1] == '/') {
                            if (j == 1 || j == 2)
                            {
                                if (j == 2)
                                    poping++;
                                break;
                            }
                        }
                    default :
                        pos = path.find('/', i + 1);
                        if (pos == string::npos)
                            pos = path.size() - 1;
                        else
                            pos--; //to remove '/' at the end of the word
                        if (!poping)
                        {
                            s.push(path.substr(i + 1, pos - i));
                            // cout << s.top() << endl;
                        }
                        else
                            poping--;
                        break;
                }
            }
        }
        string str = "/";
        while (s.size() > 0)
        {
            str += s.top();
            s.pop();
            if (s.size() != 0)
                str += "/";
        }
        return str;
    }
};