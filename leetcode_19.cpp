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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int sz = 0;
      ListNode* head_copy = head;
      while (head_copy != nullptr) {
        head_copy = head_copy->next;
        sz++;
      }
      int rm_head = sz - n;
      head_copy = head;
      
      if (rm_head == 0) {
        return head->next;
      }
      
      for (int i = 0; i < rm_head; ++i) {
        if (i == rm_head - 1) {
          head_copy->next = head_copy->next->next;
          break; 
        }
        head_copy = head_copy->next;
      }
      return head;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      if (head->next == nullptr) {
        return nullptr;
      }
      ListNode* first = head;
      for (int i = 0; i < n + 1; ++i) {
        first = first->next;
        if (first == nullptr && i != n) {
          return head->next;
        }
      }
      ListNode* second = head;
      while (first != nullptr) {
        second = second->next;
        first = first->next;
      }
      second->next = second->next->next;
      return head;
    }
};