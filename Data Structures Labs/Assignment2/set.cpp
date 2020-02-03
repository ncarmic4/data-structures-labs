/*
* Class: CS 3305 Section 01
* Term: Spring 2020
* Name: Nicholas Carmichael
* Instructor: Deepa Muralidhar
* Assignment: 2
*/

#include <iostream>
#include "set.h"

// O(1)
// precondition: there is an initial capacity
// postcondition: empty set has been created
set::set(size_type initial_capacity) {
	data = new value_type[initial_capacity];
	capacity = initial_capacity;
	used = 0;
}

// O(1)
// precondition: object exists
// postcondition: set has been deallocated
set::~set() {
	delete[] data, capacity, used;
}

// O(n) because of memcpy
// precondition: there is a source set to copy
// postcondition: a copy of source has been created
set::set(const set& source) {
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

// O(n)
// precondition: there is a set to assign and a set to read from
// postcondition: a new set has been initialized with based on source
set& set::operator= (const set &source) {
	// self assignment check
	if (this == &source)
		return *this;

	// remove any existing vars
	delete[] data, capacity, used;
	capacity = source.capacity;
	used = source.used;

	// iteratively copy data
	data = new value_type[capacity];
	for (int i = 0; i < used; i++) {
		data[i] = source.data[i];
	}

	// return lvalue
	return *this;
}

// O(1)
// precondition: there is space in the array
// postcondition: entry is in the set
void set::insert(const value_type& entry) {
	if (used == capacity) {
		return;
	}
	data[used] = entry;
	used++;
}

// O(n)
// precondition: object exists
// postcondition: entry is not in the set
void set::remove(const value_type& entry) {
	size_type index = 0;
	while (index < used) {
		if (data[index] == entry) {
			used--;
			data[index] = data[used];
		}
		index++;
	}
}

// O(1)
// precondition: object exists
// postcondition: number of elements in the set has been returned
set::size_type set::size() const {
	return used;
}

// O(n^2) because of contains()
// precondition: there is an array and value to check for
// postcondition: whether entry is in the set has been returned
bool set::contains(const value_type& entry) const {
	size_type index = 0;
	while (index < used) {
		if (data[index] == entry) {
			return true;
		}
		index++;
	}
	return false;
}

// O(n^2)
// precondition: there are two sets
// postcondition: union of s1 & s2 has been returned
set set_union(const set& s1, const set& s2) {
	// union has all values, so we can set the new set to a copy of s1 then check against s2
	set newSet(s1);
	set::size_type index = 0;
	while (index < s2.used) {
		if (!newSet.contains(s2.data[index])) {
			newSet.data[newSet.used] = s2.data[index];
			newSet.used++;
		}
		index++;
	}
	return newSet;
}

// O(n^2)
// precondition: two sets exist
// postcondition: intersection of s1 & s2 has been returned
set set_intersection(const set& s1, const set& s2) {
	set newSet;
	set::size_type index = 0;

	// looking for values that are in both sets, so check s1 with s2
	while (index < s1.used) {
		if (s2.contains(s1.data[index]) && !newSet.contains(s1.data[index])) {
			newSet.data[newSet.used] = s1.data[index];
			newSet.used++;
		}
		index++;
	}
	return newSet;
}


// O(n^2)
// precondition: two sets exist
// postcondition: difference of s1 - s2 has been returned
set set_difference(const set& s1, const set& s2) {
	set newSet;
	set::size_type index = 0;

	// looking for values in s1 that are not in s2
	while (index < s1.used) {
		if (!s2.contains(s1.data[index]) && !newSet.contains(s1.data[index])) {
			newSet.data[newSet.used] = s1.data[index];
			newSet.used++;
		}
		index++;
	}
	return newSet;
}

// O(n^2)
// precondition: two sets exist
// postcondition: returned whether s1 is a subset of s2
bool is_subset(const set& s1, const set& s2) {
	set::size_type index = 0;
	// iterate each val of s1 to check if in s2
	while (index < s1.used) {
		// if there is a single val not in s2, s1 is not a subset of s2 so return false
		if (!s2.contains(s1.data[index])) {
			return false;
		}
		index++;
	}
	return true;
}

// O(n^2)
// precondition: two sets exist
// postcondition: returned whether s1 & s2 are equal
bool operator == (const set& s1, const set& s2) {
	// because sets could be in any order we need to iterate s1 and check in s2, then iterate s2 and check in s1
	set::size_type index = 0;
	// iterate each val of s1 to check if in s2
	while (index < s1.used) {
		if (!s2.contains(s1.data[index])) {
			return false;
		}
		index++;
	}

	// reset index
	index = 0;

	// iterate each val of s2 to check if in s1
	while (index < s2.used) {
		if (!s1.contains(s2.data[index])) {
			return false;
		}
		index++;
	}

	return true;
}

// O(n)
// precondition: set exists
// postcondition: s has been displayed on output
std::ostream& operator << (std::ostream& output, const set& s) {
	for (int i = 0; i < s.used; i++) {
		output << s.data[i] << " ";
	}
	return output;
}
