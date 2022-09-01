#include "RotateKList.h"
#include <vector>
#include <iostream>

using test_case_t = std::tuple<std::vector<int>, int, std::vector<int>, bool>;
static const std::vector<test_case_t> test_cases = {
  { { 1, 2, 3, 4, 5 }, 2, { 2, 1, 4, 3, 5}, true },
  { { 1, 2, 3, 4, 5 }, 3, { 3, 2, 1, 4, 5}, true }
};

ListNode* makeList(const std::vector<int>& nums) {
  ListNode* head = new ListNode(nums[0]);
  ListNode* prev = head;
  for (int i = 1; i < nums.size(); i++) {
    ListNode* cur = new ListNode(nums[i]);
    prev->next = cur;
    prev = cur;
  }
  return head;
}

void removeList(ListNode* p_head) {
  while (p_head) {
    auto* p_tmp = p_head;
    p_head = p_head->next;
    delete p_tmp;
  }
}

bool validate_list_values(ListNode* p_head, const std::vector<int>& nums) {
  for (auto num: nums) {
    if (!p_head || p_head->value != num)
      return false;
    p_head = p_head->next;
  }
  return p_head == nullptr;
}

std::string list_to_string(ListNode* p_head) {
  std::string res;
  auto* crawler = p_head;
  while (crawler) {
    res += std::to_string(crawler->value);
    res += " ";
    crawler = crawler->next;
  }
  return res;
}

std::string vector_to_string(const std::vector<int>& nums) {
  std::string res;
  for (auto num: nums) {
    res += std::to_string(num);
    res += " ";
  }
  return res;
}

int main() {
  int error_count = 0;

  for (auto& [input_vector, k, expected_values, success]: test_cases) {
    auto* p_list = makeList(input_vector);
    std::cout << "Input   : [ " << list_to_string(p_list) << "] k = " << k << std::endl;;

    auto* p_rotated_list = rotateKList(p_list, k);
    bool compare_result = validate_list_values(p_rotated_list, expected_values);
    std::cout << "Output. : [ " << list_to_string(p_rotated_list) << "]" << std::endl;
    std::cout << "Expected: [ " << vector_to_string(expected_values) << "]" << std::endl;

    std::cout << "Expected result " << success << " Got " << compare_result << std::endl;
    if (success != compare_result) {
      error_count++;
      std::cout << "FAIL!" << std::endl;
    } 
    std::cout << "-------------" << std::endl;

    removeList(p_rotated_list);
  }
  return error_count;
}

