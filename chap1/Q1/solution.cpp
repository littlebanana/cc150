// Implement an algorithm to determine if a string has all unique characters.
// What if you can not use additional data structures?

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
	public:
		bool allUnique1(string s)
		{
			if (s.empty())
			{
				return true;
			}
			int l = s.length();
			unordered_set<char> tab;
			for (int i = 0; i < l; i++)
			{
				auto it = tab.find(s[i]);
				if (it != tab.end())
				{
					return false;
				}
				else
				{
					tab.insert(s[i]);
				}
			}
			return true;
		}

		bool allUnique2(string s)
		{
			if (s.empty())
			{
				return true;
			}

			sort(s.begin(), s.end());
			int l = s.length();
			for (int i = 1; i < l; i++)
			{
				if (s[i] == s[i-1])
				{
					return false;
				}
			}
			return true;
		}
};

int main()
{
	Solution solu;

	string s = "";
	cout << solu.allUnique2(s) << endl;
	s = "a";
	cout << solu.allUnique2(s) << endl;
	s = "abcdefg";
	cout << solu.allUnique2(s) << endl;
	s = "abcadefg";
	cout << solu.allUnique2(s) << endl;

	return 0;
}
