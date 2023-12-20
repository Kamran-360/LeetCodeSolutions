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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();  // Dummy node to represent the head of the result list
        ListNode* current = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            int sum = x + y + carry;
            carry = sum / 10;

            current->next = new ListNode(sum % 10);
            current = current->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return dummy->next;  // The next node of the dummy is the head of the result list
    }
};
/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
(You may assume the two numbers do not contain any leading zero, except the number 0 itself.
exmaple)  THIS ADDITION IS FROM LEFT TO RIGHT
  2 4 3 (l1)
+ 5 6 4 (l2)
  7 0 8      
  when we added 4 and 6 it is creating leading zero in the result
  which is 10 so we write 0 as sum and one would be carried to the 
  next col so  (3+4+carried 1) = 8 the final answer would be 708
*/
