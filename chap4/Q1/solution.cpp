// Implement a function to check if a tree is balanced.
// For the purpose of this question, a balanced tree is defined to be
// a tree such that no two leaf nodes differ in distance from the root by more than one.

// Different difinitions of leaf lead to different results

#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
	public:
		bool isBalanced(TreeNode *root, int &min, int &max)
		{
			if (root->left == NULL && root->right == NULL)
			{
				min = 1;
				max = 1;
				return true;
			}
			else if (root->left == NULL)
			{
				int rmin = 0;
				int rmax = 0;
				if (!isBalanced(root->right, rmin, rmax))
				{
					return false;
				}
				min = rmin + 1;
				max = rmax + 1;
				return true;
			}
			else if (root->right == NULL)
			{
				int lmin = 0;
				int lmax = 0;
				if (!isBalanced(root->left, lmin, lmax))
				{
					return false;
				}
				min = lmin + 1;
				max = lmax + 1;
				return true;
			}
			else
			{
				int lmin = 0;
				int lmax = 0;
				int rmin = 0;
				int rmax = 0;
				if (!isBalanced(root->left, lmin, lmax) || !isBalanced(root->right, rmin, rmax))
				{
					return false;
				}
				max = (lmax > rmax ? lmax : rmax);
				min = (lmin > rmin ? rmin : lmin);
				if (max > min + 1)
				{
					return false;
				}
				max++;
				min++;
				return true;
			}
		}

		int maxDepth(TreeNode *root)
		{
			if (root == NULL)
			{
				return 0;
			}
			return 1 + max(maxDepth(root->left), maxDepth(root->right));
		}

		int minDepth(TreeNode *root)
		{
			if (root == NULL)
			{
				return 0;
			}
			return 1 + min(minDepth(root->left), minDepth(root->right));
		}

		bool isBalanced(TreeNode *root)
		{
			if (root == NULL)
			{
				return true;
			}
			int min = 0;
			int max = 0;
			return isBalanced(root, min, max);
		}

		bool isBalanced2(TreeNode *root)
		{
			return (maxDepth(root) - minDepth(root) <= 1);
		}
};

int main()
{
	Solution solu;

	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(4);
	root->left->left->left->left = new TreeNode(5);
	root->right = new TreeNode(6);
//	root->right->left = new TreeNode(7);
	root->right->right = new TreeNode(8);
	root->right->right->left = new TreeNode(9);
	root->right->right->right = new TreeNode(10);

	cout << solu.isBalanced(root) << endl;

	return 0;
}
