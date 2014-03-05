// How would you design a stack which, in addition to push and pop,
// also has a function min which returns the minimum element?
// Push, pop and min should all operate in O(1) time.

#include <iostream>
#include <stack>

using namespace std;

class MinStack
{
    public:
        MinStack() {}
        ~MinStack() {}

        void push(int x)
        {
            if (stk.empty() || x >= stk.top())
            {
                minstk.push(x);
            }
            stk.push(x);
        }

        int pop()
        {
            if (stk.empty())
            {
                cerr << "The stack is empty." << endl;
                return -1;
            }

            if (stk.top() == minstk.top())
            {
                minstk.pop();
            }
            int tmp = stk.top();
            stk.pop();
            return tmp;
        }

        int min()
        {
            if (minstk.empty())
            {
                cerr << "The stack is empty." << endl;
                return -1;
            }

            return minstk.top();
        }

    private:
        stack<int> stk;
        stack<int> minstk;
};

int main()
{
    MinStack stk;
    cout << stk.pop() << endl;
    cout << stk.min() << endl;
    stk.push(1);
    cout << "min = " << stk.min() << endl;
    stk.push(2);
    cout << "min = " << stk.min() << endl;
    stk.push(7);
    cout << "min = " << stk.min() << endl;
    stk.push(4);
    cout << "min = " << stk.min() << endl;
    stk.push(3);
    cout << "min = " << stk.min() << endl;
    stk.push(8);
    cout << "min = " << stk.min() << endl;
    stk.push(6);
    cout << "min = " << stk.min() << endl;
    cout << stk.pop() << endl;
    cout << "min = " << stk.min() << endl;
    cout << stk.pop() << endl;
    cout << "min = " << stk.min() << endl;
    cout << stk.pop() << endl;
    cout << "min = " << stk.min() << endl;
    cout << stk.pop() << endl;
    cout << "min = " << stk.min() << endl;
    cout << stk.pop() << endl;
    cout << "min = " << stk.min() << endl;
    cout << stk.pop() << endl;
    cout << "min = " << stk.min() << endl;


    return 0;
}
