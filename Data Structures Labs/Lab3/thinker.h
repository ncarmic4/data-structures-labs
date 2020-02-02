// FILE: thinker.h
/*
* Class: CS 3305 Section 01
* Term: Spring 2020
* Name: Nicholas Carmichael
* Instructor: Deepa Muralidhar
* Assignment: Lab 3
*/

class thinking_cap
{
public:
    void slots(const char new_green[], const char new_red[]); // added const to both parameters
    void push_green() const;
    void push_red() const;
private:
    char green_string[50];
    char red_string[50];
};