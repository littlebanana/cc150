// Write an algorithm such that if an element in an MxN matrix is 0,
// its entire rwo and column is set to 0.

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    public:
        void setZeros(vector<vector<int> > &matrix)
        {
            int M = matrix.size();
            int N = matrix[0].size();

            bool row = false;
            for (int j = 0; j < N; j++)
            {
                if (matrix[0][j] == 0)
                {
                    row = true;
                    break;
                }
            }
            bool col = false;
            for (int i = 0; i < M; i++)
            {
                if (matrix[i][0] == 0)
                {
                    col = true;
                    break;
                }
            }
            for (int i = 1; i < M; i++)
            {
                for (int j = 1; j < M; j++)
                {
                    if (matrix[i][j] == 0)
                    {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }

            for (int j = 1; j < N; j++)
            {
                if (matrix[0][j] == 0)
                {
                    for (int i = 0; i < M; i++)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
            for (int i = 1; i < M; i++)
            {
                if (matrix[i][0] == 0)
                {
                    for (int j = 0; j < N; j++)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
            if (row)
            {
                for (int j = 0; j < N; j++)
                {
                    matrix[0][j] = 0;
                }
            }
            if (col)
            {
                for (int i = 0; i < M; i++)
                {
                    matrix[i][0] = 0;
                }
            }
        }
};

void initMatrix(vector<vector<int> > &matrix)
{
    int M = matrix.size();
    int N = matrix[0].size();
    int val = 1;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = val++;
        }
    }
}

void printMatrix(vector<vector<int> > &matrix)
{
    int M = matrix.size();
    int N = matrix[0].size();

    cout << "[";
    for (int i = 0; i < M; i++)
    {
        if (i > 0)
        {
            cout << " ";
        }
        for (int j = 0; j < N; j++)
        {
            cout << matrix[i][j];
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

    int M = 4;
    int N = 6;

    vector<vector<int> > matrix(M, vector<int>(N));

    initMatrix(matrix);
    matrix[0][1] = 0;
    matrix[1][2] = 0;
    printMatrix(matrix);

    solu.setZeros(matrix);
    printMatrix(matrix);

    return 0;
}
