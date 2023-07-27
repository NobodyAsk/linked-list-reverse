#include "solution.h"
#include "tests.h"
#include <iostream>

int main() {
	int list_size = 0;
	std::cout << "Input linked list's size (> 0): " << std::endl;
	std::cin >> list_size;
	if (list_size > 0) {
		ListNode* new_node = new ListNode(0);
		ListNode* head = new_node;
		for (int it = 1; it < list_size; ++it) {
			new_node->next = new ListNode(it);
			new_node = new_node->next;
		}
		TestSolution(std::cout, head);
		system("PAUSE");
	}
	else {
		std::cout << "Wrong input.";
		system("PAUSE");
	}
}