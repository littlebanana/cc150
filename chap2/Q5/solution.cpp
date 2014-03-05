// Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.
// DEFINITION:
// Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node,
// so as to make a loop in the linked list.
// EXAMPLE:
// input:  A->B->C->D->E->C [the same C as earlier]
// output: C

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
        ListNode *locateLoop(ListNode *head)
        {
            if (head == NULL)
            {
                return NULL;
            }

            ListNode *fast = head->next;
            ListNode *slow = head;
            while (fast != NULL)
            {
                if (fast->next == NULL || fast == slow)
                {
                    break;
                }
                fast = fast->next->next;
                slow = slow->next;
            }
            if (fast == NULL || fast->next == NULL)
            {
                return NULL;
            }
            fast = fast->next;
            slow = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
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
    solu.locateLoop(t);
    cout << solu.locateLoop(t) << endl;
    t = new ListNode(1);
    t->next = t;
    cout << solu.locateLoop(t) << endl;

    return 0;
}
