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
    auto* p_sector_start = p_prev_sector_end->next;
    auto* p_next_sector_start = p_sector_end->next;

    auto* p_prev_node = p_sector_start;
    auto* p_cur_node = p_prev_node->next;
    while (p_cur_node != p_next_sector_start) {
      auto* p_next_node = p_cur_node->next;
      p_cur_node->next = p_prev_node;
      p_prev_node = p_cur_node;
      p_cur_node = p_next_node;
    }

    p_sector_start->next = p_next_sector_start;
    p_prev_sector_end->next = p_sector_end;
    p_prev_sector_end = p_sector_start;
  }
  return fake_node.next;
}
