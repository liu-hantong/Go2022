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
      ListNode* head = new ListNode(0);
      ListNode* tail = head;
      int carry = 0;
      while (l1 != nullptr && l2 != nullptr) {
        int sum = l1->val + l2->val + carry;
        int store = sum % 10;
        carry = sum / 10;
        ListNode* cur = new ListNode(store);
        tail->next = cur;
        tail = cur;
        l1 = l1->next;
        l2 = l2->next;
      }
      
      if (l1 == nullptr && l2 != nullptr) {
        while (l2 != nullptr) {
          int sum = l2->val + carry;
          int store = sum % 10;
          carry = sum / 10;
          ListNode* cur = new ListNode(store);
          tail->next = cur; 
          tail = cur;
          l2 = l2->next;
        } 
      }
      else if (l2 == nullptr && l1 != nullptr) {
        while (l1 != nullptr) {
          int sum = l1->val + carry;
          int store = sum % 10;
          carry = sum / 10;
          ListNode* cur = new ListNode(store);
          tail->next = cur; 
          tail = cur;
          l1 = l1->next;
        }
      }
      if (carry != 0) {
        ListNode* cur = new ListNode(carry);
        tail->next = cur;
      }
      
      return head->next;
    }
};