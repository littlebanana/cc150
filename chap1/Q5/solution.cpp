// Write a method to replace all spaces in a string with '%20'.

#include <iostream>
#include <string>

using namespace std;

class Solution
{
    public:
        string replace(string s)
        {
            if (s.empty())
            {
                return s;
            }

            int l = s.length();
            string ret = "";
            for (int i = 0; i < l; i++)
            {
                if (s[i] != ' ')
                {
                    ret += s[i];	// append(1,s[i])
                }
                else
                {
                    ret += "%20";
                }
            }
            return ret;
        }

        string replace2(string s)
        {
            if (s.empty())
            {
                return s;
            }

            int l = s.length();
            string ret = "";
            bool space = false;
            for (int i = 0; i < l; i++)
            {
                if (s[i] != ' ')
                {
                    if (space)
                    {
                        ret += "%20";
                        space = false;
                    }
                    ret += s[i];	// append(1,s[i])
                }
                else
                {
                    space = true;
                }
            }
            // DON'T FORGET TO CHECK THE LAST ONE!
            if (space)
            {
                ret += "%20";
            }
            return ret;
        }

        string replace3(string s)
        {
            if (s.empty())
            {
                return s;
            }

            int l = s.length();
            int sp = 0;
            for (int i = 0; i < l; i++)
            {
                if (s[i] == ' ')
                {
                    sp++;
                }
            }

            int newl = l + 2*sp;
            string ret(newl, ' ');
            int j = 0;
            for (int i = 0; i < l; i++)
            {
                if (s[i] == ' ')
                {
                    ret[j++] = '%';
                    ret[j++] = '2';
                    ret[j++] = '0';
                }
                else
                {
                    ret[j++] = s[i];
                }
            }
            return ret;
        }

};

int main()
{
    Solution solu;

    string s = "";
    cout << s << "|" << solu.replace3(s) << endl;
    s = " ";
    cout << s << "|" << solu.replace3(s) << endl;
    s = "a";
    cout << s << "|" << solu.replace3(s) << endl;
    s = "a ";
    cout << s << "|" << solu.replace3(s) << endl;
    s = " a";
    cout << s << "|" << solu.replace3(s) << endl;
    s = "   a";
    cout << s << "|" << solu.replace3(s) << endl;
    s = "a   ";
    cout << s << "|" << solu.replace3(s) << endl;
    s = "a b   c   ";
    cout << s << "|" << solu.replace3(s) << endl;

    return 0;
}
