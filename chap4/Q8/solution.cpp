// You are given a binary tree in which each node contains a value.
// Design an algorithm to print all paths which sum up to that value.
// Note that it can by any path in the tree - it does not have to start at the root.

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printTree(TreeNode *root)
{
	// print in level order
	queue<TreeNode *> Q;
	Q.push(root);
	int n = 1;
	while (!Q.empty())
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			TreeNode *t = Q.front();
			Q.pop();
			if (t == NULL)
			{
				cout << "# ";
			}
			else
			{
				cout << t->val << " ";
				Q.push(t->left);
				Q.push(t->right);
				cnt += 2;
			}
		}
		cout << endl;
		n = cnt;
	}
}

class Solution
{
	public:
		void printPaths(TreeNode *root)
		{
		}
};

int main()
{
	return 0;
}
