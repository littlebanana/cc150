// Given a directed graph, design an algorithm to find out whether there is a route between two nodes.

#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

struct GraphNode
{
	int val;
	vector<GraphNode *> neighbors;
	GraphNode(int x) : val(x), neighbors() {}
};

class Solution
{
	public:
		bool isReachable(GraphNode *src, GraphNode *des)
		{
			// BFS
			if (src == NULL || des == NULL)
			{
				return false;
			}

			unordered_set<GraphNode *> visited;
			queue<GraphNode *> Q;
			Q.push(src);
			while (!Q.empty())
			{
				GraphNode *t = Q.front();
				Q.pop();
				visited.insert(t);
				for (int i = 0; i < t->neighbors.size(); i++)
				{
					GraphNode *p = t->neighbors[i];
					if (p == des)
					{
						return true;
					}
					if (visited.find(p) == visited.end())
					{
						Q.push(p);
					}
				}
			}
			return false;
		}
};

int main()
{
	GraphNode *n1 = new GraphNode(1);
	GraphNode *n2 = new GraphNode(2);
	GraphNode *n3 = new GraphNode(3);
	GraphNode *n4 = new GraphNode(4);
	n1->neighbors.push_back(n2);
	n2->neighbors.push_back(n3);
	n4->neighbors.push_back(n1);

	Solution solu;
	cout << solu.isReachable(n1, n3) << endl;
	cout << solu.isReachable(n1, n4) << endl;

	return 0;
}
