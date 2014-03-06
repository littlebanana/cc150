// Image a robot sitting on the upper left hand corner of an NxN grid.
// The robot can only move in two directions: right and down.
// How many possible paths are there for the robot?
// FOLLOWUP:
// Imagine certain squares are "off limits", such that the robot can not step on them.
// Design an algorithm to get all poissible paths for the robot.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		int numberOfPaths(const vector<vector<char> > &grid)
		{
			if (grid.empty() || grid[0].empty())
			{
				return 0;
			}

			int M = grid.size();
			int N = grid[0].size();
			int num[M];
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
				{
				}
			}
			return num[M-1];
		}
};

int main()
{
	return 0;
}
