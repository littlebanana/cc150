// Implement a data structure SetOfStacks.
// SetOfStacks should be composed of several stacks, and should create a new stack once the previous one exceeds capacity.
// SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack
// (that is, pop() should return the same values as it would if there were just a single stack).
// FOLLOWUP:
// Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class SetOfStacks
{
    public:
        SetOfStacks(int n = 2) : capacity(n), top(1, -1), data(1, vector<int>(n)) {}

        void push(int x)
        {
            if (top.back() == capacity-1)
            {
                top.push_back(-1);
                vector<int> stk(capacity);
                data.push_back(stk);
            }
            top.back()++;
            data.back()[top.back()] = x;
        }

        int pop()
        {
            int tmp = data.back()[top.back()];
            top.back()--;
            if (top.back() < 0)
            {
                top.pop_back();
                data.pop_back();
            }
            return tmp;
        }

        int popAt(int k)
        {
            if (k > data.size())
            {
                cerr << "invalid k" << endl;
                return -1;
            }
            list<int>::iterator itop = top.begin();
            for (int i = 0; i < k; i++, itop++);
            list<vector<int> >::iterator idata = data.begin();
            for (int i = 0; i < k; i++, idata++);
            int tmp = (*idata)[*itop];
            (*itop)--;
            if (*itop < 0)
            {
                top.erase(itop);
                data.erase(idata);
            }
            return tmp;
        }

    private:
        int capacity;
        list<int> top;
        list<vector<int> > data;
};

int main()
{
    SetOfStacks stks;

    stks.push(1);
    stks.push(2);
    stks.push(3);
    stks.push(4);
    stks.push(5);
    stks.push(6);
    stks.push(7);
    stks.push(8);
    stks.push(9);
    stks.push(10);
    stks.push(11);
    stks.push(12);
    cout << stks.pop() << endl;
    cout << stks.pop() << endl;
    cout << stks.pop() << endl;
    cout << stks.popAt(2) << endl;
    cout << stks.popAt(2) << endl;
    cout << stks.popAt(2) << endl;

    return 0;
}
