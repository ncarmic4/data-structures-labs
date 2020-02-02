/////////////////// Program 2.2
/*
* Class: CS 3305 Section 01
* Term: Spring 2020
* Name: Nicholas Carmichael
* Instructor: Deepa Muralidhar
* Assignment: Lab 3
*/

#include <iostream>
using namespace std;

void m(int[]); // changed function definition, removed first int

// removed p function as it is not being used anywhere

int main()
{
    // declare x int and y int array
    int x = 1;
    int y[10];
    // removed set y[0] = 1 because it is being overriden in function m
    m(y); // removed x from number parameter position
    cout << "x is " << x << endl;
    cout << "y[0] is " << y[0] << endl;
    return 0;
}

void m(int numbers[]) // removed number parameter and declared in function as it was being overwritten
{
    int number = 1001;
    numbers[0] = 5555;
}