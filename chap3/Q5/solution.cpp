// Implement a MyQueue class which implements a queue using two stacks

#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
    public:
        MyQueue() : size(0) {}

        void push(int x)
        {
            tail.push(x);
            size++;
        }

        int front() const
        {
            if (head.empty())
            {
                while (!tail.empty())
                {
                    int tmp = tail.top();
                    tail.pop();
                    head.push(tmp);
                }
            }
            int ret = head.top();
            return ret;
        }

        int pop()
        {
            if (isEmpty())
            {
                cerr << "Queue is empty!" << endl;
                return -1;
            }

            if (head.empty())
            {
                while (!tail.empty())
                {
                    int tmp = tail.top();
                    tail.pop();
                    head.push(tmp);
                }
            }
            int ret = head.top();
            head.pop();
            return ret;
        }

        bool isEmpty() const
        {
            return (size == 0);
        }

    private:
        int size;
        mutable stack<int> head;
        mutable stack<int> tail;
};

int main()
{
    MyQueue Q;
    cout << Q.pop() << endl;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    cout << Q.front() << endl;
    cout << Q.pop() << endl;
    Q.push(4);
    cout << Q.front() << endl;
    Q.push(5);
    Q.push(6);
    cout << Q.front() << endl;
    cout << Q.pop() << endl;
    cout << Q.pop() << endl;
    cout << Q.pop() << endl;

    return 0;
}
