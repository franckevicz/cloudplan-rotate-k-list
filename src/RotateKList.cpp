#include "RotateKList.h"

namespace {
  ListNode* getNthNode(ListNode* head, int k) {
    auto* p_crawler = head;
    while (p_crawler && k > 0) {
      p_crawler = p_crawler->next;
      k--;
    }
    return p_crawler;
  }
} // anonymous namespace

ListNode* rotateKList(ListNode* head, int k) {
  if (!head || k < 2)
    return head;
    
  ListNode fake_node(0);
  fake_node.next = head;
    
  ListNode* p_prev_sector_end = &fake_node;
    
  while (auto* p_sector_end = getNthNode(p_prev_sector_end, k)) {
    //do the reverse
  }
  return fake_node.next;
}
