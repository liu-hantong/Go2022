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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      if (list1 == nullptr) {
        return list2;
      }
      if (list2 == nullptr) {
        return list1;
      }
      ListNode* d1 = new ListNode(0, list1);
      ListNode* d2 = new ListNode(0, list2);
      ListNode* res = new ListNode(0, nullptr);
      ListNode* res_copy = res;
      while (d1->next != nullptr && d2->next != nullptr) {
        ListNode* out;
        if (d1->next->val >= d2->next->val) {
          out = d2->next;
          d2->next = d2->next->next;
        }
        else {
          out = d1->next;
          d1->next = d1->next->next;
        }
        out->next = res_copy->next;
        res_copy->next = out;
        res_copy = out;
      }
      while (d1->next != nullptr) {
          ListNode* out = d1->next;
          d1->next = d1->next->next;
          out->next = res_copy->next;
          res_copy->next = out;
          res_copy = out;
      }
      while (d2->next != nullptr) {
          ListNode* out = d2->next;
          d2->next = d2->next->next;
          out->next = res_copy->next;
          res_copy->next = out;
          res_copy = out;
      }
      return res->next;
    }
};