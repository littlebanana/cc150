// Write an algorithm to print all ways of arrange eight queens on a chess board
// so that none of them share the same row, column or diagonal

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
    public:
        bool isValid(const vector<string> &board, int ii, int jj)
        {
            int N = board.size();

            // skip checking rows

            // check columns
            for (int i = 0; i < N; i++)
            {
                if (i != ii && board[i][jj] == 'Q')
                {
                    return false;
                }
            }

            // check diagonals
            for (int i = 0; i < N; i++)
            {
                int j = jj-(i-ii);
                if (j != jj && j >= 0 && j < N && board[i][j] == 'Q')
                {
                    return false;
                }
                j = jj+(i-ii);
                if (j != jj && j >= 0 && j < N && board[i][j] == 'Q')
                {
                    return false;
                }
            }
            return true;
        }

        void solve(vector<string> &board, int ii, vector<vector<string> > &solutions)
        {
            int N = board.size();
            if (ii == N)
            {
                solutions.push_back(board);
                return;
            }

            for (int j = 0; j < N; j++)
            {
                if (board[ii][j] == '.' && isValid(board, ii, j))
                {
                    board[ii][j] = 'Q';
                    solve(board, ii+1, solutions);
                    board[ii][j] = '.';
                }
            }
        }

        vector<vector<string> > solveNQueens(int n)
        {
            vector<string> board(n, string(n, '.'));
            vector<vector<string> > solutions;
            solve(board, 0, solutions);
            return solutions;
        }
};

void printBoard(const vector<string> &board)
{
    int N = board.size();
    cout << "[";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j > 0)
            {
                cout << " ";
            }
            cout << board[i][j];
            if (j < N-1)
            {
                cout << " ";
            }
        }
        if (i < N-1)
        {
            cout << endl;
        }
    }
    cout << "]" << endl;
}

int main()
{
    Solution solu;
    vector<vector<string> > solutions = solu.solveNQueens(4);
    for (int i = 0; i < solutions.size(); i++)
    {
        printBoard(solutions[i]);
    }

    return 0;
}
