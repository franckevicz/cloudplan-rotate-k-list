#include "RotateKList.h"
#include <vector>
#include <iostream>

using test_case_t = std::tuple<std::vector<int>, int, std::vector<int>, bool>;
static const std::vector<test_case_t> test_cases = {
  { { 1, 2, 3, 4, 5 }, 2, { }, false },             //to check false condition
  { { 1, 2, 3, 4, 5 }, 2, { 2, 1, 4, 3, 5 }, true },
  { { 1, 2, 3, 4, 5 }, 3, { 3, 2, 1, 4, 5 }, true },
  { { 1, 2, 3, 4, 5 }, 3, { 3, 2, 1, 4, 5, 5 }, false },
  { { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 2, { 2, 1, 4, 3, 6, 5, 8, 7, 9 }, true },
  { { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 3, { 3, 2, 1, 6, 5, 4, 9, 8 ,7 }, true },
  { { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 4, { 4, 3, 2, 1, 8, 7, 6, 5, 9 }, true },
  { { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 5, { 5, 4, 3, 2, 1, 6, 7, 8, 9 }, true },
  { { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 6, { 6, 5, 4, 3, 2, 1, 7, 8, 9 }, true },
  { { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 7, { 7, 6, 5, 4, 3, 2, 1, 8, 9 }, true },
  { { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 8, { 8, 7, 6, 5, 4, 3, 2, 1, 9 }, true },
  { { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 9, { 9, 8, 7, 6, 5, 4, 3, 2, 1 }, true },
  { { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 10, { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, true },
  { { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 100, { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, true },
  { { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 1, { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, true },
  { { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 1, { 1, 1, 2, 3, 4, 5, 6, 7, 8 }, false },
  { { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, 1, { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, false },
  { { -1, -2, -3, -4, -5, -6, -7, -8, -9 }, 2, { -2, -1, -4, -3, -6, -5, -8, -7, -9 }, true },
  { { -1, -2, -3, -4, -5, -6, -7, -8, -9 }, 3, { -3, -2, -1, -6, -5, -4, -9, -8 ,-7 }, true },
  { { 10000000, 20000000, 30000000, 40000000, 50000000, 60000000, 70000000, 80000000, 90000000 }, 2, { 20000000, 10000000, 40000000, 30000000, 60000000, 50000000, 80000000, 70000000, 90000000 }, true },
  { { 1, 1, 1, 1, 1, 1, 1, 1 }, 1, { 1, 1, 1, 1, 1, 1, 1, 1 }, true },
  { { 1, 1, 1, 1, 1, 1, 1, 1 }, 2, { 1, 1, 1, 1, 1, 1, 1, 1 }, true },
  { { 1, 1, 1, 1, 1, 1, 1, 1 }, 3, { 1, 1, 1, 1, 1, 1, 1, 1 }, true },
  { { 1, 1, 1, 1, 1, 1, 1, 1 }, 8, { 1, 1, 1, 1, 1, 1, 1, 1 }, true },
  { { 1, 1, 1, 1, 1, 1, 1, 1 }, 100, { 1, 1, 1, 1, 1, 1, 1, 1 }, true },
  { { 0, 0, 0, 0, 0, 0, 0, 0 }, 2, { 0, 0, 0, 0, 0, 0, 0, 0 }, true },
  { { 9, 8 ,7, 6 }, 1, { 9, 8 ,7, 6 }, true },
  { { 9, 8 ,7, 6 }, 2, { 8, 9 ,6 ,7 }, true },
  { { 9, 8 ,7, 6 }, 3, { 7, 8, 9 ,6 }, true },
  { { 9, 8 ,7, 6 }, 4, { 6, 7, 8, 9 }, true },
  { { 9, 8 ,7, 6 }, 5, { 9, 8 ,7, 6 }, true },
  { { 9, 8 ,7, 6 }, 10, { 9, 8 ,7, 6 }, true },
  { { }, 1, { }, true },
  { { }, 10, { }, true },
  { { 1 }, 1, { 1 }, true },
  { { 1 }, 2, { 1 }, true },
  { { 1, 2 }, 0 , { 1, 2 }, true },
  { { 1, 2 }, -1, { 1, 2 }, true },
};

ListNode* makeList(const std::vector<int>& nums) {
  if (nums.empty())
    return nullptr;

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
  auto* p_crawler = p_head;
  while (p_crawler) {
    res += std::to_string(p_crawler->value);
    res += " ";
    p_crawler = p_crawler->next;
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
  std::cout << "Number of errors " << error_count << std::endl;
  return error_count;
}

