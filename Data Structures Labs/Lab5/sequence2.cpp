#include "sequence2.h"
#include <cstdlib>

using namespace main_savitch_4;

sequence::sequence(size_t initial_capacity = DEFAULT_CAPACITY) {
	capacity = initial_capacity;
	used = 0;
	data = new value_type[capacity];
}

sequence::sequence(const sequence& source) {
	capacity = source.capacity;
	used = source.used;
	// iteratively copy data
	data = new value_type[capacity];
	size_type index = 0;
	while (index < used) {
		data[index] = source.data[index];
		index++;
	}
}

sequence::~sequence() {
	//delete[] used, data, capacity;
}

void sequence::resize(size_type new_capacity) {
	value_type* larger_array;
	if (new_capacity == capacity) {
		return;
	}

	if (new_capacity < used) {
		new_capacity = used;
	}

	larger_array = new value_type[new_capacity];
	std::copy

	delete[] data;
	data = larger_array;
	capacity = new_capacity;
}

void sequence::start() {
	if (used == 0)
		return;

	data[0] = current();
}

void sequence::advance() {
	if (current() == data[used - 1])
		return;

	current_index++;
}

void sequence::insert(const value_type& entry) {
	used++;
	if (used > capacity) {
		resize(used);
	}

	sequence newSeq(capacity);
	size_type index = 0;
	while (index < used) {
		if (index == current_index) {
			newSeq.data[index] = entry;
		}
		else {
			newSeq.data[index] = data[index];
		}
		index++;
	}
	data = newSeq.data;
	newSeq.~sequence();
}

void sequence::attach(const value_type& entry) {
	used++;
	if (used > capacity) {
		resize(used);
	}

	sequence newSeq(capacity);
	size_type index = 0;
	while (index < used) {
		if (index == current_index + 1) {
			newSeq.data[index] = entry;
		}
		else {
			newSeq.data[index] = data[index];
		}
		index++;
	}
	data = newSeq.data;
	newSeq.~sequence();
}

void sequence::remove_current() {

}

void sequence::operator=(const sequence& source) {

}

sequence::size_type sequence::size() const {
	return used;
}

bool sequence::is_item() const {

}

sequence::value_type sequence::current() const {

}

