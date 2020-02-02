///////////////// Program 2.1
/*
* Class: CS 3305 Section 01
* Term: Spring 2020
* Name: Nicholas Carmichael
* Instructor: Deepa Muralidhar
* Assignment: Lab 3
*/

#include <iostream>
using namespace std;

const int SIZE = 4; // added equals sign
void printArray(int list[], int arraySize);

void reverse(const int list[], int newList[], int size)
{
    for (int i = 0, j = size - 1; i < size; i++, j--)
    {
        newList[j] = list[i];
    }
}

void p(int list[], int arraySize) // removed const on list to make it modifiable
{
    list[0] = 100;
}

int main()
{
    // size is already defined and const so I removed the assignment

    int newList[SIZE];
    int numbers[] = { 1, 4, 3, 6, 8 };

    p(numbers, 5);
    printArray(numbers, 5);

    reverse(numbers, newList, SIZE); // set to pass "numbers" array instead of undeclared "list" var
    printArray(newList, SIZE);
    return 0;
}
void printArray(int list[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        cout << list[i] << " ";
    }
}

