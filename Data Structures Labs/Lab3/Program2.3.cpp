/////////////////// Program 2.3
/*
* Class: CS 3305 Section 01
* Term: Spring 2020
* Name: Nicholas Carmichael
* Instructor: Deepa Muralidhar
* Assignment: Lab 3
*/

#include <iostream>
using namespace std;

// will swap variables but not their references, so will not be swapped in main method
void swap1(int n1, int n2) 
{
    // not referencing main method vars
    int temp = n1;
    n1 = n2;
    n2 = temp;
}
// swaps vars using references 
void swap2(int& n1, int& n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}
// swaps vars using pointers
void swap3(int* p1, int* p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// swaps pointers, p1 now points to p2, etc
void swap4(int*& p1, int*& p2)
{
    int* temp = p1;
    p1 = p2;
    p2 = temp;
}

int main()
{
    // declare initial values
    int num1 = 1;
    int num2 = 2;
    cout << "Before invoking the swap1 function, num1 is "
        << num1 << " and num2 is " << num2 << endl;
    // call swap1, shouldn't swap the numbers here but it will in the function
    swap1(num1, num2);
    cout << "After invoking the swap1 function, num1 is " << num1 <<
        " and num2 is " << num2 << endl;
    cout << "Before invoking the swap2 function, num1 is "
        << num1 << " and num2 is " << num2 << endl;
    // call swap 2, swaps references
    swap2(num1, num2);
    cout << "After invoking the swap2 function, num1 is " << num1 <<
        " and num2 is " << num2 << endl;
    cout << "Before invoking the swap3 function, num1 is "
        << num1 << " and num2 is " << num2 << endl;
    // call swap 3, swap using pointers
    swap3(&num1, &num2);
    cout << "After invoking the swap3 function, num1 is " << num1 <<
        " and num2 is " << num2 << endl;
    // create pointers for the nums
    int* p1 = &num1;
    int* p2 = &num2;
    cout << "Before invoking the swap4 function, p1 is "
        << p1 << " and p2 is " << p2 << endl;
    // calll swap4, swap the pointers
    swap4(p1, p2);
    cout << "After invoking the swap4 function, p1 is " << p1 <<
        " and p2 is " << p2 << endl;
    return 0;
}