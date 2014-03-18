// Implement an algorithm to find the n-th to last element of a singly linked list

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    public:
        int findKthLastElement(ListNode *head, int k)
        {
            if (head == NULL)
            {
                return -1;
            }

            ListNode *last = head;
            ListNode *kth = head;
            int cnt = k;
            while (last->next != NULL)
            {
                if (cnt > 1)
                {
                    cnt--;
                    last = last->next;
                }
                else
                {
                    kth = kth->next;
                    last = last->next;
                }
            }

            return (cnt > 1 ? -1 : kth->val);
        }
};

void destroyList(ListNode *l)
{
    while (l != NULL)
    {
        ListNode *tmp = l;
        l = l->next;
        delete tmp;
    }
}

void printList(ListNode *l)
{
    cout << "[";
    while (l != NULL)
    {
        cout << l->val ;
        if (l->next != NULL)
        {
            cout << "->";
        }
        l = l->next;
    }
    cout << "]" << endl;
}

int main()
{
    Solution solu;

    ListNode *t = NULL;
    printList(t);
    int k = 1;
    cout << k << "-th = " << solu.findKthLastElement(t, k) << endl;
    k = 0;
    cout << k << "-th = " << solu.findKthLastElement(t, k) << endl;
    t = new ListNode(1);
    printList(t);
    k = 1;
    cout << k << "-th = " << solu.findKthLastElement(t, k) << endl;
    k = 2;
    cout << k << "-th = " << solu.findKthLastElement(t, k) << endl;
    t->next = new ListNode(2);
    t->next->next = new ListNode(3);
    t->next->next->next = new ListNode(4);
    t->next->next->next->next = new ListNode(5);
    printList(t);
    k = 1;
    cout << k << "-th = " << solu.findKthLastElement(t, k) << endl;
    k = 2;
    cout << k << "-th = " << solu.findKthLastElement(t, k) << endl;
    k = 3;
    cout << k << "-th = " << solu.findKthLastElement(t, k) << endl;
    k = 4;
    cout << k << "-th = " << solu.findKthLastElement(t, k) << endl;
    k = 5;
    cout << k << "-th = " << solu.findKthLastElement(t, k) << endl;
    k = 6;
    cout << k << "-th = " << solu.findKthLastElement(t, k) << endl;
    k = 7;
    cout << k << "-th = " << solu.findKthLastElement(t, k) << endl;

    destroyList(t);

    return 0;
}
