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

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode* res = new ListNode(0, nullptr);
      ListNode* res_copy = res;
      while (l1 != nullptr && l2 != nullptr) {
        if (l1->val <= l2->val) {
          res_copy->next = l1;
          l1 = l1->next;
        }
        else {
          res_copy->next = l2;
          l2 = l2->next;
        }
        res_copy = res_copy->next;
      }
      
      res_copy->next = l1 == nullptr ? l2 : l1;
      return res->next;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      if (list1 == nullptr) {
        return list2;
      }
      else if (list2 == nullptr) {
        return list1;
      }
      else if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
      }
      else {
        list2->next = mergeTwoLists(list2->next, list1);
        return list2;
      }
    }
};
