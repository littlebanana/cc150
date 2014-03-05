// Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node
// EXAMPLE:
// INPUT: the node 'c' from the linked list a->b->c->d->e
// OUPUT: nothing is returned, but the new linked list look likes a->b->d->e

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
        void removeElement(ListNode *t)
        {
            if (t == NULL || t->next == NULL)
            {
                return;
            }

            ListNode *tbd = t->next;
            t->val = t->next->val;
            t->next = t->next->next;
            delete tbd;
        }
};

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
    t = new ListNode(1);
    t->next = new ListNode(2);
    t->next->next = new ListNode(3);
    t->next->next->next = new ListNode(4);
    t->next->next->next->next = new ListNode(5);
    printList(t);
    solu.removeElement(t->next->next);
    printList(t);

    return 0;
}
