#pragma once

#include "solution.h"
#include "log_duration.h"
#include <string>
#include <iostream>
#include <sstream>
#include <cassert>

// Return initial list
void PrintInitialList(std::ostream& out, ListNode* head) {
	auto temp = head;
	while (temp->next != NULL) {
		out << &temp->val << " with value " << temp->val << std::endl;
		temp = temp->next;
	}
	out << &temp->val << " with value " << temp->val << std::endl;
}

ListNode* Test1(std::ostream& out, ListNode* head) {
	Solution solve;
	ListNode* for_rewind = head;
	{
		LOG_DURATION("Reversal by iterations: ");
		auto temp = solve.ReverseList1(head);
		for_rewind = temp;
		while (temp->next != NULL) {
			out << &temp->val << " with value " << temp->val << "\n";
			temp = temp->next;
		}
		out << &temp->val << " with value " << temp->val << std::endl;
	}
	return for_rewind;
}
ListNode* Test2(std::ostream& out, ListNode* head) {
	Solution solve;
	ListNode* for_rewind = head;
	{
		LOG_DURATION("Recursive reversal: ");
		auto temp = solve.ReverseList2(head);
		for_rewind = temp;
		while (temp->next != NULL) {
			out << &temp->val << " with value " << temp->val << "\n";
			temp = temp->next;
		}
		out << &temp->val << " with value " << temp->val << std::endl;
	}
	return for_rewind;
}

void ReverseListIterat(ListNode* head) {
	Solution solve;
	solve.ReverseList1(head);
}

void ReverseListRecursive(ListNode* head) {
	Solution solve;
	solve.ReverseList2(head);
}

void TestSolution(std::ostream& out, ListNode* head) {
	out << "Initial list is: " << std::endl;
	PrintInitialList(out, head);
	out << "Reversal list by iteration method: " << std::endl;
	ListNode* temp = Test1(out, head);
	ReverseListIterat(temp);
	out << "Reversal list by recursive method: " << std::endl;
	temp = Test2(out, head);
	ReverseListRecursive(temp);
	out << "The end list is: " << std::endl;
	PrintInitialList(out, head);
}