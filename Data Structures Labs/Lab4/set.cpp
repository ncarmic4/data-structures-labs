/*
* Class: CS 3305 Section 01
* Term: Spring 2020
* Name: Nicholas Carmichael
* Instructor: Deepa Muralidhar
* Assignment: Lab 2
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

}

set::set(const set& s) {

}

set& set::operator= (const set& s) {
    set newSet = s;
    return newSet;
}

bool set::erase(const value_type& target) {
    size_type index = 0;
    std::cout << "test";
    while (index < used)
    {
        std::cout << data[index] << " " << target;
        if (data[index] == target)
        {
            --used;
            data[index] = data[used];
            return true;
        }
        else
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

}

set::size_type set::size() const {
    return capacity;
}

bool set::contains(const value_type& target) const {
    int index = 0;
    
    while (index < used)
    {
        if (data[index] == target)
        {
            return true;
        }
        else
            ++index;
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

