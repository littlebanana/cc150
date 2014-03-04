// Design an algorithm and write code to remove the duplicate characters in a string without using any additional buffer.
// NOTE: One or two additional variables are find. An extra copy of the array is not.
// FOLLOWUP: Write the test cases for this method.

#include <iostream>
#include <string>

using namespace std;

class Solution
{
	public:
	string removeDuplicates(string s)
	{
		if (s.empty() || s.length() == 1)
		{
			return s;
		}

		for (int i = 0; i < s.length()-1; i++)
		{
			for (int j = s.length()-1; j > i; j--)
			{
				if (s[i] == s[j])
				{
					s.erase(s.begin()+j);
					j++;
				}
			}
		}
		return s;
	}

	string removeDuplicates2(string s)
	{
		if (s.empty() || s.length() == 1)
		{
			return s;
		}

		int l = s.length();
		int tail = 0;			// s[0...tail] is the string without duplicates
		for (int i = 1; i < l; i++)
		{
			// check s[i] with the previous characters
			bool duplicate = false;
			for (int j = 0; j < i; j++)
			{
				if (s[i] == s[j])
				{
					duplicate = true;
					break;
				}
			}
			if (!duplicate)
			{
				s[tail+1] = s[i];
				tail++;
			}
		}
		s.erase(tail+1);
		return s;
	}
};

int main()
{
	Solution solu;

	string s = "";
	cout << s << " ";
	cout << solu.removeDuplicates2(s) << endl;
	s = "a";
	cout << s << " ";
	cout << solu.removeDuplicates2(s) << endl;
	s = "aaaa";
	cout << s << " ";
	cout << solu.removeDuplicates2(s) << endl;
	s = "abacadaaa";
	cout << s << " ";
	cout << solu.removeDuplicates2(s) << endl;

	return 0;
}
