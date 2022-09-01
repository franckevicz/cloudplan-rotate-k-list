#pragma once

struct ListNode {
  int       value;
  ListNode* next;

  ListNode(int x) : value(x), next(nullptr){}; 
};

ListNode* rotateKList(ListNode* head, int k);