#pragma once
#include <iostream>

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int x)
		: val(x), next(NULL)
	{
	}
};

class Solution {
public:
	// Method by iterations
	ListNode* ReverseList1(ListNode* head) {
		if (head->next == NULL) { return head; }
		ListNode* next_node = head->next;
		head->next = NULL;
		while (next_node->next != NULL) {
			ListNode* new_node = next_node->next;
			next_node->next = head;
			head = next_node;
			next_node = new_node;
		}
		next_node->next = head;
		return next_node;
	}
	// Method by recursion
	ListNode* ReverseList2(ListNode* head) {
		if (head->next == NULL) {
			return head;
		}
		ListNode* temp = ReverseList2(head->next);
		head->next->next = head;
		head->next = NULL;
		return temp;
	}
};