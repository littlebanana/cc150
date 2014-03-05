// Given a sorted (increasing order) array, write an algorithm to create a binary tree with minimal height

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

class Solution
{
	public:
		TreeNode* buildSubtree(int A[], int left, int right)
		{
			if (left > right)
			{
				return NULL;
			}

			int mid = left + (right-left)/2;
			TreeNode *root = new TreeNode(A[mid]);
			root->left = buildSubtree(A, left, mid-1);
			root->right = buildSubtree(A, mid+1, right);
			return root;
		}

		TreeNode* buildTree(int A[], int n)
		{
			return buildSubtree(A, 0, n-1);
		}
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

int main()
{
	int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

	Solution solu;
	TreeNode *t = solu.buildTree(A, 11);
	printTree(t);

	return 0;
}
