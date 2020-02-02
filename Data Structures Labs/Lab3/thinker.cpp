// FILE: thinker.cpp
/*
* Class: CS 3305 Section 01
* Term: Spring 2020
* Name: Nicholas Carmichael
* Instructor: Deepa Muralidhar
* Assignment: Lab 3
*/

#include <iostream> // removed .h
#include <stdlib.h>
#include "thinker.h"
#include <cassert> // added include for assert statements

using namespace std; // added namespace

void thinking_cap::slots(const char new_green[], const char new_red[]) // added const to both parameters
{
    assert(strlen(new_green) < 50);
    assert(strlen(new_red) < 50);
    strcpy_s(green_string, new_green); // changed to use strcpy_s because of visual studio error
    strcpy_s(red_string, new_red); // changed to use strcpy_s because of visual studio error
}
void thinking_cap::push_green () const // added "() const" to match header file
{
 cout << green_string << endl;
}
void thinking_cap::push_red () const // added "() const" to match header file
{
 cout << red_string << endl;
}