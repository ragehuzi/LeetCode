/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void addElement(ListNode *&head, int x)
    {
        ListNode *temp = new ListNode(x);

        if (head == nullptr)
        {
            head = temp;
            return;
        }

        ListNode *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = temp;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *newlist = nullptr;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr)
        {
            int sum = 0;
            if (l2 == nullptr)
            {
                sum = l1->val + carry;
                l1 = l1->next;
            }
            else if (l1 == nullptr)
            {
                sum = l2->val + carry;
                l2 = l2->next;
            }
            else
            {
                sum = l2->val + l1->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }

            if (sum > 9)
            {
                carry = sum / 10;
                sum = sum % 10;
            }
            else
            {
                carry = 0;
            }
            addElement(newlist, sum);
        }
        if (carry > 0)
        {
            addElement(newlist, carry);
        }
        return newlist;
    }
};