// Implement an algorithm to print all valid (e.g., properly opened and closed) combinations of n-pairs of parenthesis
// EXAMPLE:
// input: 3 (e.g., 3 pairs of parenthesis)
// output: ()()(), ()(()), (())(), ((()))

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
    public:
        void generate(string s, const int n, int l, int u, vector<string> &para)
        {
            // n = # of '('/')' required
            // l = # of '(' already got
            // u = # of '(' unmatched in s
            if (l == n)
            {
                s.append(u, ')');
                para.push_back(s);
                return;
            }

            // add one more '('
            generate(s+'(', n, l+1, u+1, para);

            // match '('s and add one more '('
            for (int i = 1; i <= u; i++)
            {
                s += ')';
                generate(s+'(', n, l+1, u-i+1, para);
            }
        }

        vector<string> generateParenthesis(int n)
        {
            vector<string> para;
            generate("", n, 0, 0, para);
            return para;
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
    vector<string> para = solu.generateParenthesis(0);
    printStrings(para);

    para = solu.generateParenthesis(1);
    printStrings(para);

    para = solu.generateParenthesis(2);
    printStrings(para);

    para = solu.generateParenthesis(4);
    printStrings(para);

    return 0;
}
