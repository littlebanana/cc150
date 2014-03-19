// Solve Hanoi.
// Rules:
// (a) Only one disk can be moved at a time.
// (b) A disk is slid off the top of one rod onto the next rod.
// (c) A disk can only be placed on top of a larger disk.

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Hanoi
{
    public:
        Hanoi(int size = 10) : n(size), T(vector<stack<int> >(3))
        {
            reset();
        }

        // rest to the start state
        void reset()
        {
            for (int i = 0; i < 3; i++)
            {
                while (!T[i].empty())
                {
                    T[i].pop();
                }
            }
            for (int i = n; i > 0; i--)
            {
                T[0].push(i);
            }
        }

        void moveTopK(int k, int start, int end, int mid)
        {
            if (k == 0)
            {
                return;
            }
            if (k == 1)
            {
                T[end].push(T[start].top());
                T[start].pop();

                printTowers();
            }
            else
            {
                moveTopK(k-1, start, mid, end);
                T[end].push(T[start].top());
                T[start].pop();
                printTowers();
                moveTopK(k-1, mid, end, start);
            }
        }

        void solve()
        {
            moveTopK(n, 0, 2, 1);
        }

        void printTowers()
        {
            stack<int> tmp;
            for (int i = 0; i < 3; i++)
            {
                while (!T[i].empty())
                {
                    tmp.push(T[i].top());
                    T[i].pop();
                }
                cout << "Tower " << i << ": ";
                while (!tmp.empty())
                {
                    cout << tmp.top() << " ";
                    T[i].push(tmp.top());
                    tmp.pop();
                }
                cout << endl;
            }
            cout << endl;
        }

    private:
        int n;
        vector<stack<int> > T;
};

int main()
{
    Hanoi hanoi(4);

    cout << "The start state:" << endl;
    hanoi.printTowers();

    hanoi.solve();

    cout << "The end state:" << endl;
    hanoi.printTowers();

    return 0;
}
