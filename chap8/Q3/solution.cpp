// Write a method that returns all subsets of a set

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printSets(const vector<vector<int> > &sets);

class Solution
{
	public:
		vector<vector<int> > allSubsetsDup(const vector<int> &set)
		{
			vector<vector<int> > subsets;
			vector<int> tmp;		// empty set
			subsets.push_back(tmp);

			vector<int> sorted = set;
			sort(sorted.begin(), sorted.end());

			int L = sorted.size();
			int prev = 0;
			for (int i = 0; i < L; i++)
			{
				int start = ((i > 0 && sorted[i] == sorted[i-1]) ? prev : 0);
				int n = subsets.size();
				for (int j = start; j < n; j++)
				{
					vector<int> tmp = subsets[j];
					tmp.push_back(sorted[i]);
					subsets.push_back(tmp);
				}
				prev = n;
			}
			return subsets;
		}

		vector<vector<int> > generateSubsets(const vector<int> &set, int left)
		{
			int L = set.size();
			if (left == L)
			{
				return vector<vector<int> >(1, vector<int>());
			}

			vector<vector<int> > subsets = generateSubsets(set, left+1);
			int n = subsets.size();
			for (int i = 0; i < n; i++)
			{
				vector<int> tmp = subsets[i];
				tmp.push_back(set[left]);
				subsets.push_back(tmp);
			}
			return subsets;
		}

		vector<vector<int> > allSubsets(const vector<int> &set)
		{
			vector<int> sorted = set;
			return generateSubsets(sorted, 0);
		}
};

void printSets(const vector<vector<int > > &sets)
{
	cout << "[";

	if (!sets.empty())
	{
		int M = sets.size();
		for (int i = 0; i < M; i++)
		{
			if (i > 0)
			{
				cout << " ";
			}
			cout << "[";
			int N = sets[i].size();
			for (int j = 0; j < N; j++)
			{
				cout << sets[i][j];
				if (j < N-1)
				{
					cout << ", ";
				}
			}
			cout << "]";
			if (i < M-1)
			{
				cout << "," << endl;
			}
		}
	}

	cout << "]" << endl;
}

int main()
{
	vector<int> set;

	Solution solu;
	vector<vector<int> > subsets = solu.allSubsets(set);
	printSets(subsets);

	set.push_back(1);
//	set.push_back(1);
	subsets = solu.allSubsets(set);
	printSets(subsets);
/*
	set.push_back(1);
	subsets = solu.allSubsets(set);
	printSets(subsets);

	set.push_back(1);
	set.push_back(1);
	subsets = solu.allSubsets(set);
	printSets(subsets);
*/
	set.push_back(2);
	set.push_back(3);
	set.push_back(4);
	subsets = solu.allSubsets(set);
	printSets(subsets);


	return 0;
}
