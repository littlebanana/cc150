// Assume you have a method isSubstring which checks if one word is a substring of another.
// Given two strings s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring.
// (i.e. "waterbottle" is a rotation of "erbottlewat")

#include <iostream>
#include <string>

using namespace std;

class Solution
{
    public:
        bool isRotation(string s1, string s2)
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

            string s1s1 = s1 + s1;
            return (s1s1.find(s2) < 2*l1);
        }
};

int main()
{
    Solution solu;

    string s1 = "";
    string s2 = "";
    cout << solu.isRotation(s1, s2) << endl;
    s1 = "ab";
    s2 = "bac";
    cout << solu.isRotation(s1, s2) << endl;
    s1 = "ab";
    s2 = "ba";
    cout << solu.isRotation(s1, s2) << endl;
    s1 = "aa";
    s2 = "aa";
    cout << solu.isRotation(s1, s2) << endl;
    s1 = "aabaa";
    s2 = "abaaa";
    cout << solu.isRotation(s1, s2) << endl;
    s1 = "aabca";
    s2 = "abaac";
    cout << solu.isRotation(s1, s2) << endl;

    return 0;
}
