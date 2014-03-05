// Describe how you could use a single array to implement three stacks

#include <iostream>

using namespace std;

class ThreeStacks
{
    public:
        ThreeStacks() : top1(-1), top2(-1), top3(-1), bound(-1), capacity(6)
        {
            data = new int[6];
        }

        ~ThreeStacks()
        {
            delete[] data;
        }

        void push1(int x)
        {
            if (top1 + 3 > capacity-1)
            {
                resize(2*capacity);
            }
            top1 = (top1 == -1 ? 0 : top1+=3);
            bound = (top1 > bound ? top1 : bound);
            data[top1] = x;
        }

        void push2(int x)
        {
            if (top2 + 3 > capacity-1)
            {
                resize(2*capacity);
            }
            top2 = (top2 == -1 ? 0 : top2+=3);
            bound = (top2 > bound ? top2 : bound);
            data[top2] = x;
        }

        void push3(int x)
        {
            if (top3 + 3 > capacity-1)
            {
                resize(2*capacity);
            }
            top3 = (top3 == -1 ? 0 : top3+=3);
            bound = (top3 > bound ? top3 : bound);
            data[top3] = x;
        }

        int pop1()
        {
            if (top1 == -1)
            {
                cerr << "stack 1 is empty!" << endl;
                return -1;
            }
            else
            {
                int tmp = data[top1];
                top1 = (top1 == 0 ? -1 : top1-=3);
                bound = (bound > top1 ? bound : top1);
                if (bound < capacity/4)
                {
                    resize(capacity/2);
                }
                return tmp;
            }
        }

        int pop2()
        {
            if (top2 == -1)
            {
                cerr << "stack 2 is empty!" << endl;
                return -1;
            }
            else
            {
                int tmp = data[top2];
                top2 = (top2 == 1 ? -1 : top2-=3);
                bound = (bound > top2 ? bound : top2);
                if (bound < capacity/4)
                {
                    resize(capacity/2);
                }
                return tmp;
            }
        }

        int pop3()
        {
            if (top3 == -1)
            {
                cerr << "stack 3 is empty!" << endl;
                return -1;
            }
            else
            {
                int tmp = data[top3];
                top3 = (top3 == 2 ? -1 : top3-=3);
                bound = (bound > top3 ? bound : top3);
                if (bound < capacity/4)
                {
                    resize(capacity/2);
                }
                return tmp;
            }

        }

    private:
        void resize(int n)
        {
            int *tmp = new int[n];
            int l = (n > capacity ? capacity : n);
            for (int i = 0; i < l; i++)
            {
                tmp[i] = data[i];
            }
            delete[] data;
            capacity = n;
            data = tmp;
        }

        int *data;
        int top1;
        int top2;
        int top3;
        int bound;
        int capacity;
};

int main()
{
    ThreeStacks stks;
    stks.push1(1);
    stks.push1(2);
    cout << stks.pop1() << endl;
    cout << stks.pop1() << endl;
    cout << stks.pop1() << endl;
    stks.push3(100);
    stks.push3(200);
    stks.push3(300);
    stks.push3(400);
    stks.push3(500);
    stks.push3(600);
    stks.push3(700);
    stks.push3(800);
    stks.push3(900);
    stks.push3(1000);
    stks.push3(1100);
    stks.push3(1200);
    stks.push3(1300);
    stks.push3(1400);
    stks.push3(1500);
    stks.push3(1600);
    cout << stks.pop2() << endl;
    cout << stks.pop3() << endl;
    cout << stks.pop3() << endl;
    cout << stks.pop3() << endl;
    cout << stks.pop3() << endl;
    cout << stks.pop3() << endl;
    cout << stks.pop3() << endl;
    cout << stks.pop3() << endl;
    cout << stks.pop3() << endl;
    cout << stks.pop3() << endl;
    cout << stks.pop3() << endl;

    return 0;
}
