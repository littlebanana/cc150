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

            // 2*(a+b) = a + b + c + b - 1; because fast starts one step ahead
            // a = c - 1;
            // so need to advance c one step ahead
            ListNode *fast = head->next;    // critical
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
            fast = fast->next;      // critical
            slow = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }

        ListNode *locateLoop2(ListNode *head)
        {
            ListNode *fast = head;
            ListNode *slow = NULL;
            while (fast != NULL && fast != slow)
            {
                if (fast->next == NULL || fast->next->next == NULL)
                {
                    return NULL;
                }
                slow = (slow == NULL ? head->next : slow->next);
                fast = fast->next->next;
            }
            if (fast == NULL)
            {
                return NULL;
            }
            slow = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
};

void destroyList(ListNode *l, ListNode *node)
{
    while (l != NULL && l->next != node)
    {
        ListNode *tmp = l;
        l = l->next;
        delete tmp;
    }
    delete l;
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
    solu.locateLoop(t);
    cout << solu.locateLoop2(t) << endl;

    t = new ListNode(1);
    t->next = new ListNode(2);
    t->next->next = new ListNode(3);
    t->next->next->next = new ListNode(4);
    t->next->next->next->next = new ListNode(5);
    t->next->next->next->next->next = t->next->next;

    ListNode* node = solu.locateLoop2(t);
    cout << node->val << endl;

    destroyList(t, node);

    return 0;
}
