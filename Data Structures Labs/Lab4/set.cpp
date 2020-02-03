/*
* Class: CS 3305 Section 01
* Term: Spring 2020
* Name: Nicholas Carmichael
* Instructor: Deepa Muralidhar
* Assignment: Lab 4
*/

#include <cstdlib>;
#include <cstring>
#include "set.h";

// implementation of set.h set class
set::set(size_type initial_capacity) {
    data = new value_type[initial_capacity];
    capacity = initial_capacity;
    used = 0;
}

set::~set() {
    delete[] data, capacity, used;
}

set::set(const set& s) {
    capacity = s.capacity;
    used = s.used;
    // iteratively copy data
    data = new value_type[capacity];
    size_type index = 0;
    while (index < used) {
        data[index] = s.data[index];
        index++;
    }
}

set& set::operator= (const set& s) {
    // self assignment check
    if (this == &s)
        return *this;

    // remove any existing vars
    delete[] data, capacity, used;
    capacity = s.capacity;
    used = s.used;

    // iteratively copy data
    data = new value_type[capacity];
    for (int i = 0; i < used; i++) {
        data[i] = s.data[i];
    }

    // return lvalue
    return *this;
}

bool set::erase(const value_type& target) {
    size_type index = 0;
    while (index < used)
    {
        if (data[index] == target)
        {
            --used;
            data[index] = data[used];
            return true;
        }
        ++index;
    }
    return false;
}

bool set::insert(const value_type& entry) {
    if (used == capacity)
        reserve(used + 1);
    data[used] = entry;
    ++used;
    return true;
}

void set::operator+=(const set& addend) {
    // need to make sure there is enough capacity for max amount possible
    value_type totalCapacity = addend.used + used;
    if (totalCapacity > capacity) {
        reserve(totalCapacity);
    }

    // union has all values, only once
    size_type index = 0;
    while (index < addend.used) {
        if (!contains(addend.data[index])) {
            data[used] = addend.data[index];
            used++;
        }
        index++;
    }
}

set::size_type set::size() const {
    return used;
}

bool set::contains(const value_type& target) const {
    size_type index = 0;
    while (index < used) {
        if (data[index] == target) {
            return true;
        }
        index++;
    }
    return false;
}

std::ostream& operator<<(std::ostream& output, const set& s) {
    for (int i = 0; i < s.used; i++) {
        output << s.data[i] << " ";
    }
    return output;
}

void set::reserve(size_type new_capacity) {
    value_type* larger_array;
    if (new_capacity == capacity) {
        return;
    }

    if (new_capacity < used) {
        new_capacity = used;
    }

    larger_array = new value_type[new_capacity];
    std::copy(data, data + used, larger_array);
    delete[] data;
    data = larger_array;
    capacity = new_capacity;
}
