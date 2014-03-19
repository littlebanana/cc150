// Write a program to sort a stack in ascending order.
// You should not make any assumptoins about how the stack is implemented.
// The following are the only functions that should be used to write this program:
// push | pop | peek | isEmpty

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
    public:
        // recursive approach
        void sortStack(stack<int> &stk)
        {
            if (stk.empty())
            {
                return;
            }

            int top = stk.top();
            stk.pop();

            sortStack(stk);

            stack<int> tmp;
            while (!stk.empty() && top < stk.top())
            {
                tmp.push(stk.top());
                stk.pop();
            }
            stk.push(top);
            while (!tmp.empty())
            {
                stk.push(tmp.top());
                tmp.pop();
            }
        }

        // iterative approach
        void sortStack2(stack<int> &stk)
        {
            // use a temporary which grows in the reverse sorted order
            stack<int> tmp;

            while (!stk.empty())
            {
                int top = stk.top();
                stk.pop();
                if (tmp.empty() || top <= tmp.top())
                {
                    tmp.push(top);
                }
                else
                {
                    int cnt = 0;
                    while (!tmp.empty() && top > tmp.top())
                    {
                        cnt++;
                        stk.push(tmp.top());
                        tmp.pop();
                    }
                    tmp.push(top);
                    for (int i = 0; i < cnt; i++)
                    {
                        tmp.push(stk.top());
                        stk.pop();
                    }
                }
            }
            while (!tmp.empty())
            {
                stk.push(tmp.top());
                tmp.pop();
            }
        }

        // iterative approach, shorter version
        void sortStack3(stack<int> &stk)
        {
            // use a temporary which grows in the reverse sorted order
            stack<int> tmp;

            while (!stk.empty())
            {
                int top = stk.top();
                stk.pop();
                while (!tmp.empty() && top > tmp.top())
                {
                    stk.push(tmp.top());
                    tmp.pop();
                }
                tmp.push(top);
            }
            while (!tmp.empty())
            {
                stk.push(tmp.top());
                tmp.pop();
            }
        }
};

void printStack(stack<int> &stk)
{
    cout << "Stack: (bottom->top)" << endl;

    stack<int> tmp;
    while (!stk.empty())
    {
        tmp.push(stk.top());
        stk.pop();
    }
    while (!tmp.empty())
    {
        cout << tmp.top() << " ";
        stk.push(tmp.top());
        tmp.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> stk;
    stk.push(3);
    stk.push(2);
    stk.push(5);
    stk.push(9);
    stk.push(4);
    stk.push(6);
    stk.push(4);
    stk.push(8);
    stk.push(1);

    printStack(stk);

    Solution solu;
    solu.sortStack3(stk);

    printStack(stk);

    return 0;
}
