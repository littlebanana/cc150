// Write a method to decide if two strings are anagrams or not.

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
    public:
        bool isAnagram1(string s1, string s2)
        {
            if (s1.empty() && s2.empty())
            {
                return true;
            }

            int l1 = s1.length();
            int l2 = s2.length();
            if (l1 != l2)
            {
                return false;
            }

            unordered_map<char,int> cnt;
            for (int i = 0; i < l1; i++)
            {
                auto it = cnt.find(s1[i]);
                if (it != cnt.end())
                {
                    it->second++;
                }
                else
                {
                    cnt.insert(pair<char,int>(s1[i],1));
                }
            }

            for (int i = 0; i < l2; i++)
            {
                auto it = cnt.find(s2[i]);
                if (it == cnt.end() || it->second == 0)
                {
                    return false;
                }
                else
                {
                    it->second--;
                }
            }
            for (int i = 0; i < l2; i++)
            {
                if (cnt.find(s2[i])->second > 0)
                {
                    return false;
                }
            }
            return true;
        }

        bool isAnagram2(string s1, string s2)
        {
            if (s1.empty() && s2.empty())
            {
                return true;
            }
            int l1 = s1.length();
            int l2 = s2.length();
            if (l1 != l2)
            {
                return false;
            }

            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());

            return (s1.compare(s2) == 0);
        }
};

int main()
{
    Solution solu;

    string s1 = "";
    string s2 = "";
    cout << solu.isAnagram2(s1, s2) << endl;
    s1 = "";
    s2 = "a";
    cout << solu.isAnagram2(s1, s2) << endl;
    s1 = "a";
    s2 = "a";
    cout << solu.isAnagram2(s1, s2) << endl;
    s1 = "ab";
    s2 = "ba";
    cout << solu.isAnagram2(s1, s2) << endl;
    s1 = "bb";
    s2 = "ba";
    cout << solu.isAnagram2(s1, s2) << endl;

    return 0;
}
