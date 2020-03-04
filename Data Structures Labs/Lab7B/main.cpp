#include <cstdlib>
#include <iostream>
#include "node1.h"
#include "check_lists.h"

using namespace std;
using namespace main_savitch_5;

void list_print(node* head_ptr) {
	if (head_ptr == NULL)
		return;
	node* next = head_ptr;

	// start brackets
	cout << "{ ";
	while (next != NULL) {
		cout << next->data() << " ";
		next = next->link();
	}
	// close brackets
	cout << "}" << endl; 
}

int main() {
	// test 1
	node* test1head = new node(23.5);

	list_head_insert(test1head, 45.6);
	list_head_insert(test1head, 67.7);
	list_head_insert(test1head, 89.8);
	list_head_insert(test1head, 12.9);

	list_print(test1head);
	check_list1(test1head);


	// test 2
	node* test2head = new node(23.5);
	node* test2tail = test2head;

	list_insert(test2tail, 45.6);
	list_insert(test2tail->link(), 67.7);
	list_insert(test2tail->link()->link(), -123.5);
	list_insert(test2tail->link()->link()->link(), 89.8);
	list_insert(test2tail->link()->link()->link()->link(), 12.9);

	list_print(test2head);
	check_list2(test2head);


	// test 3
	node* test3head;
	node* test3tail;
	list_copy(test1head, test3head, test3tail);
	list_print(test3head);
	check_list1(test3head);
	cout << "at tail3: " << test3tail->data() << endl;


	// test 4
	list_head_remove(test2head);
	list_print(test2head);
	check_list2B(test2head);


	// test 5
	list_remove(test2head->link());
	list_print(test2head);
	check_list2C(test2head);
}