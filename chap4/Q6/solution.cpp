// Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree.
// Avoid storing additional nodes in a data structure.
// NOTE: This is not necessarily a binary search tree.

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
		TreeNode* firstCommonAncestor(TreeNode *p, TreeNode *q)
		{
		}
};

int main()
{
	return 0;
}
