/*
* Class: CS 3305 Section 01
* Term: Spring 2020
* Name: Nicholas Carmichael
* Instructor: Deepa Muralidhar
* Assignment: Lab 5
*/

#include "sequence2.h"
#include <cstdlib>
#include <iostream>
#include <cstring>     // Provides memcpy.

using namespace main_savitch_4;

// Postcondition: array allocated
sequence::sequence(size_t initial_capacity) {
	capacity = initial_capacity;
	used = 0;
	current_index = 0;
	data = new value_type[capacity];
}

// Precondition: There is a source to copy
// Postcondition: source data has been copied
sequence::sequence(const sequence& source) {
	capacity = source.capacity;
	used = source.used;
	current_index = source.current_index;

	delete[] data;
	data = new value_type[capacity];
	size_type index = 0;

	while (index < used) {
		data[index] = source.data[index];
		index++;
	}
}

sequence::~sequence() {
	delete[] data;
}

// Postcondition: new array has updated size and data
void sequence::resize(size_type new_capacity) {
	// make sure capacity is not less than used or is already the same
	if (new_capacity == capacity) {
		return;
	}

	if (new_capacity < used) {
		new_capacity = used;
	}

	// copy data into a larger array, then assign data to this array
	value_type* larger_array = new value_type[new_capacity];
	std::copy(data, data + used, larger_array);
	delete[] data;
	data = larger_array;
	capacity = new_capacity;
}

// Postcondition: Current index set to start of sequence
void sequence::start() {
	current_index = 0;
}

// Precondition: is_item returns true 
// Postcondition: current index has been updated
void sequence::advance() {
	if (is_item()) {
		current_index++;
	}
}

// Precondition: There is an item to add
// Postcondition: The entry has been added before current_index
void sequence::insert(const value_type& entry) {
	// in case there is no data
	if (used == 0) {
		used++;
		data[current_index] = entry;
		return;
	}

	// in case current index is off the sequence
	if (!is_item()) {
		current_index = 0;
	}

	// increase data and resize if necessary
	used++;
	if (used > capacity) {
		resize(used);
	}

	size_type index = used - 1;
	size_type insertPosition;
	insertPosition = current_index;
	
	// shift data in array before the insertPosition right one position
	while (index > insertPosition) {
		data[index] = data[index - 1];
		index--;
	}

	data[insertPosition] = entry;
}

// Precondition: There is an item to add
// Postcondition: The entry has been added after current_index
void sequence::attach(const value_type& entry) {
	// in case there is no data
	if (used == 0) {
		used++;
		data[current_index] = entry;
		return;
	}

	// in case current index is off the sequence
	if (!is_item()) {
		current_index = used - 1;
	}

	// increase data and resize if necessary
	used++;
	if (used > capacity) {
		resize(used);
	}
	
	size_type index = used - 1;
	size_type insertPosition = current_index + 1;

	// shift data in array after the insertPosition right one position
	while (index > insertPosition) {
		data[index] = data[index - 1];
		index--;
	}

	data[insertPosition] = entry;
	current_index++;
}

// Precondition: is_item returns true.
// Postcondition: The current item has been removed from the sequence,
// and current_index updated
void sequence::remove_current() {
	// in case current index is off the sequence
	if (!is_item()) {
		current_index = used - 1;
	}

	used--;
	size_type index = current_index;
	// shift data after current left one position
	while (index < used) {
		data[index] = data[index + 1];
		index++;
	}
}

// Precondition: There is a source to copy
// Postcondition: The source has been copied to this object
void sequence::operator=(const sequence& source) {
	// self assignment check
	if (this == &source)
		return;

	capacity = source.capacity;
	used = source.used;
	current_index = source.current_index;

	// iteratively copy data
	data = new value_type[capacity];
	size_type index = 0;
	while (index < used) {
		data[index] = source.data[index];
		index++;
	}
}

// Return size
sequence::size_type sequence::size() const {
	return used;
}

// Postcondition: True: valid item in sequence. False: not valid
bool sequence::is_item() const {
	// if there is no data, or if current index is off the sequence, then current is not an item
	if (used == 0 || current_index >= used) {
		return false;
	}
	else {
		return true;
	}

}

// Precondition: is_item( ) returns true.
// Postcondition: The item returned is the current item in the sequence.
sequence::value_type sequence::current() const {
	if (is_item())
		return data[current_index];
	else
		return data[0];
}

