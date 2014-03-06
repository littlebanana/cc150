// Write a method to computer all permutations of a string

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
	public:
		void permute(string &s, int start, vector<string> &perm)
		{
			int l = s.length();
			if (start == l)
			{
				perm.push_back(s);
				return;
			}

			for (int i = start; i < l; i++)
			{
				if (i > start && s[i] == s[i-1])
				{
					continue;
				}
				swap(s[i], s[start]);
				permute(s, start+1, perm);
				swap(s[i], s[start]);
			}
		}

		vector<string> permutation(string s)
		{
			vector<string> perm;
			permute(s, 0, perm);
			return perm;
		}
};

void printStrings(const vector<string> &strs)
{
	int n = strs.size();
	cout << "[";
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
		{
			cout << " ";
		}
		cout << strs[i];
		if (i < n-1)
		{
			cout << "," << endl;
		}
	}
	cout << "]" << endl;
}

int main()
{
	Solution solu;

	string s = "";
	vector<string> perm = solu.permutation(s);
	printStrings(perm);

	s = "1";
	perm = solu.permutation(s);
	printStrings(perm);

	s = "11";
	perm = solu.permutation(s);
	printStrings(perm);

	s = "112";
	perm = solu.permutation(s);
	printStrings(perm);

	s = "123";
	perm = solu.permutation(s);
	printStrings(perm);

	return 0;
}
