// Given a binary search tree, design an algorithm which creates a linked list of all the nodes at each depeth
// (i.e., if you have a tree with depth D, you'll have D linked lists).

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
	public:
		vector<ListNode *> levelLists(TreeNode *root)
		{
			if (root == NULL)
			{
				return vector<ListNode *>();
			}

			vector<ListNode *> level;
			queue<TreeNode *> Q;
			Q.push(root);
			int n = 1;
			while (!Q.empty())
			{
				int cnt = 0;
				ListNode *head = NULL;
				ListNode *l = NULL;
				for (int i = 0; i < n; i++)
				{
					TreeNode *t = Q.front();
					Q.pop();
					if (i == 0)
					{
						head = new ListNode(t->val);
						l = head;
					}
					else
					{
						l->next = new ListNode(t->val);
						l = l->next;
					}
					if (t->left != NULL)
					{
						Q.push(t->left);
						cnt++;
					}
					if (t->right != NULL)
					{
						Q.push(t->right);
						cnt++;
					}
				}
				if (head != NULL)
				{
					level.push_back(head);
				}
				n = cnt;
			}
			return level;
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

void printList(ListNode *l)
{
    cout << "[";
    while (l != NULL)
    {
        cout << l->val ;
        if (l->next != NULL)
        {
            cout << "->";
        }
        l = l->next;
    }
    cout << "]" << endl;
}

int main()
{
	Solution solu;
	vector<ListNode *> level;

	TreeNode *root = NULL;
	level = solu.levelLists(root);
	for (int i = 0; i < level.size(); i++)
	{
		printList(level[i]);
	}
	cout << endl;

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	level = solu.levelLists(root);
	for (int i = 0; i < level.size(); i++)
	{
		printList(level[i]);
	}
	cout << endl;

	root->left->right = new TreeNode(4);
	level = solu.levelLists(root);
	for (int i = 0; i < level.size(); i++)
	{
		printList(level[i]);
	}
	cout << endl;

	root->left->right->right = new TreeNode(5);
	root->left->right->right->right = new TreeNode(6);
	root->right->right = new TreeNode(7);
	root->right->right->left = new TreeNode(8);
	level = solu.levelLists(root);
	for (int i = 0; i < level.size(); i++)
	{
		printList(level[i]);
	}
	cout << endl;

	return 0;
}
