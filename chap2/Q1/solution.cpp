// Write code to remove duplicates from an unsorted linked list.
// FOLLOWUP: How would you solve this problem if a temporary buffer is not allowed?

#include <iostream>
#include <unordered_set>

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
        ListNode* removeDuplicates(ListNode *head)
        {
            if (head == NULL || head->next == NULL)
            {
                return head;
            }

            unordered_set<int> tab;
            tab.insert(head->val);

            ListNode *tp = head;
            ListNode *t = head->next;
            while (t != NULL)
            {
                if (tab.find(t->val) != tab.end())
                {
                    tp->next = t->next;
                    delete t;
                    t = tp->next;
                }
                else
                {
                    tab.insert(t->val);
                    tp = t;
                    t = t->next;
                }
            }
            return head;
        }

        ListNode *removeDuplicates2(ListNode *head)
        {
            if (head == NULL || head->next == NULL)
            {
                return head;
            }

            ListNode *tp = head;
            ListNode *t = head->next;
            while (t != NULL)
            {
                ListNode *p = head;
                while (p != t)
                {
                    if (p->val == t->val)
                    {
                        break;
                    }
                    p = p->next;
                }
                if (p != t)
                {
                    tp->next = t->next;
                    delete t;
                    t = tp->next;
                }
                else
                {
                    tp = t;
                    t = t->next;
                }
            }
            return head;
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
    t = solu.removeDuplicates2(t);
    printList(t);

    t = new ListNode(1);
    printList(t);
    t = solu.removeDuplicates2(t);
    printList(t);

    t->next = new ListNode(1);
    t->next->next = new ListNode(1);
    printList(t);
    t = solu.removeDuplicates2(t);
    printList(t);

    t->next = new ListNode(2);
    t->next->next = new ListNode(1);
    t->next->next->next = new ListNode(2);
    t->next->next->next->next = new ListNode(3);
    printList(t);
    t = solu.removeDuplicates2(t);
    printList(t);

    destroyList(t);

    return 0;
}
