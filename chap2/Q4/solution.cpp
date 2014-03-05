// You have two numbers represented by a linked list, where each node contains a single digit.
// The digits are stored in reverse order, such that the 1's digit is at the head of the list.
// Write a function that adds the two numbers and returns the sum as a linked list.

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
        ListNode* addNumbers(ListNode *num1, ListNode *num2)
        {
            if (num1 == NULL)
            {
                return num2;
            }
            if (num2 == NULL)
            {
                return num1;
            }

            int carry = (num1->val+num2->val) / 10;
            ListNode *sum = new ListNode((num1->val+num2->val)%10);

            ListNode *t = sum;
            ListNode *p = num1->next;
            ListNode *q = num2->next;
            while (p != NULL && q != NULL)
            {
                int digit = p->val + q->val;
                t->next = new ListNode(digit%10);

                carry = digit / 10;
                p = p->next;
                q = q->next;
                t = t->next;
            }
            if (p == NULL)
            {
                p = q;
            }
            while (p != NULL)
            {
                int digit = p->val + carry;
                t->next = new ListNode(digit%10);
                
                carry = digit / 10;
                p = p->next;
                t = t->next;
            }
            if (carry > 0)
            {
                t->next = new ListNode(carry);
            }
            return sum;
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

    ListNode *num1 = new ListNode(0);
    num1->next = new ListNode(1);
    cout << "num 1 = ";
    printList(num1);
    ListNode *num2 = new ListNode(9);
    num2->next = new ListNode(9);
    cout << "num 2 = ";
    printList(num2);
    ListNode *sum = solu.addNumbers(num1, num2);
    cout << "sum   = ";
    printList(sum);

    return 0;
}
