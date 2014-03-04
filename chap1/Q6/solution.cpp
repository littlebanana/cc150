// Given an image represented by an NxN matrix,
// where each pixel in the image is 4 bytes,
// write a method to rotate the image by 90 degrees.
// Can you do this in place?

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
	public:
		void rotate90(vector<vector<int> > &img)
		{
			int N = img.size();

			int level = N/2;
			for (int l = 0; l < level; l++)		// shell level
			{
				for (int i = 0;	i < N-2*l-1; i++)	// offset
				{
					int tmp = img[l][l+i];
					img[l][l+i] = img[N-1-l-i][l];
					img[N-1-l-i][l] = img[N-1-l][N-1-l-i];
					img[N-1-l][N-1-l-i] = img[l+i][N-1-l];
					img[l+i][N-1-l] = tmp;
				}
			}
		}
};

void initMatrix(vector<vector<int> > &img)
{
	int M = img.size();
	int N = img[0].size();
	int val = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			img[i][j] = val++;
		}
	}
}

void printMatrix(vector<vector<int> > &img)
{
	int M = img.size();
	int N = img[0].size();

	cout << "[";
	for (int i = 0; i < M; i++)
	{
		if (i > 0)
		{
			cout << " ";
		}
		for (int j = 0; j < N; j++)
		{
			cout << img[i][j];
			if (j < N-1)
			{
				cout << " ";
			}
		}
		if (i == M-1)
		{
			cout << "]";
		}
		cout << endl;
	}

}

int main()
{
	Solution solu;

	int N = 10;
	vector<vector<int> > img(N, vector<int>(N));

	initMatrix(img);
	printMatrix(img);

	solu.rotate90(img);
	printMatrix(img);

	return 0;
}
