/*
* Class: CS 3305 Section 01
* Term: Spring 2020
* Name: Nicholas Carmichael
* Instructor: Deepa Muralidhar
* Assignment: Lab 5
*/

#include "sequence3.h"
#include <cstdlib>
#include <iostream>
#include <cstring>     // Provides memcpy.
#include "node1.h"

using namespace main_savitch_5;

// Postcondition: array allocated
sequence::sequence() {
	many_nodes = 0;
	cursor = NULL;
	precursor = NULL;
	tail_ptr = NULL;
	head_ptr = NULL;
}

// copy constructor
sequence::sequence(const sequence& source) {
	node* next = source.head_ptr;
	while (next != NULL) {
		attach(next->data());
		next = next->link();
	}
}

sequence::~sequence() {
	
}

// Postcondition: Current index set to start of sequence
void sequence::start() {
	if (many_nodes > 0) {
		cursor = head_ptr;
		precursor = NULL;
	}
}

// Precondition: is_item returns true 
// Postcondition: current index has been updated
void sequence::advance() {
	if (!is_item())
		return;
	if (cursor == tail_ptr) {
		cursor = NULL;
		precursor = tail_ptr;
	} else {
		precursor = cursor;
		cursor = cursor->link();
	}
}

// Precondition: There is an item to add
// Postcondition: The entry has been added before current_index
void sequence::insert(const value_type& entry) {
	node* newNode;

	// if sequence is empty, the newnode is head and tail
	if (many_nodes == 0) {
		newNode = new node(entry, NULL);
		head_ptr = newNode;
		tail_ptr = newNode;
		cursor = newNode;
		many_nodes++;
		return;
	}

	if (!is_item() || cursor == head_ptr) { // if cursor = NULL or head, attach at start
		newNode = new node(entry, head_ptr);
		head_ptr = newNode;
	}
	else { // if cursor is item, point newnode to cursor
		newNode = new node(entry, cursor);
		precursor->set_link(newNode);
	}

	cursor = newNode;
	many_nodes++;
}

// Precondition: There is an item to add
// Postcondition: The entry has been added after current_index
void sequence::attach(const value_type& entry) {
	node* newNode;

	// if sequence is empty, the newnode is head and tail
	if (many_nodes == 0) {
		newNode = new node(entry, NULL);
		head_ptr = newNode;
		tail_ptr = newNode;
		cursor = newNode;
		many_nodes++;
		return;
	}
	
	if (!is_item() || cursor == tail_ptr) { // if cursor = NULL, attach at end
		newNode = new node(entry, NULL);
		tail_ptr->set_link(newNode);
		tail_ptr = newNode;
	}
	else { // if cursor is item, point to new node
		newNode = new node(entry, cursor->link());
		cursor->set_link(newNode);
	}
	precursor = cursor;
	cursor = newNode;
	many_nodes++;
}

// Precondition: is_item returns true.
// Postcondition: The current item has been removed from the sequence,
// and current_index updated
void sequence::remove_current() {
	if (!is_item())
		return;

	if (many_nodes == 1) {
		cursor = NULL;
		precursor = NULL;
		tail_ptr = NULL;
		head_ptr = NULL;
	} 
	else if (cursor == tail_ptr) {
		tail_ptr = precursor;
		precursor->set_link(NULL);
		cursor = NULL;
	}
	else if (cursor == head_ptr) {
		head_ptr = cursor->link();
		precursor = NULL;
		cursor = head_ptr;
	}
	else {
		precursor->set_link(cursor->link());
		cursor = cursor->link();
	}

	many_nodes--;
}

// Precondition: There is a source to copy
// Postcondition: The source has been copied to this object
void sequence::operator=(const sequence& source) {
	many_nodes = source.many_nodes;
	if (source.many_nodes == 0) {
		head_ptr = NULL;
		tail_ptr = NULL;
		cursor = NULL;
		precursor = NULL;
		return;
	}

	node* next = source.head_ptr;
	while (next != NULL) {
		attach(next->data());
		next = next->link();
	}
}

// Precondition: is_item( ) returns true.
// Postcondition: The item returned is the current item in the sequence.
sequence::value_type sequence::current() const {
	if (is_item())
		return cursor->data();
	else
		return NULL;
}