/*
* Class: CS 3305 Section 01
* Term: Spring 2020
* Name: Nicholas Carmichael
* Instructor: Deepa Muralidhar
* Assignment: Lab 1
*/

#include <cstdlib>;
#include <iostream>

using namespace std;

void exerciseOne() {
    // output multiline string
    cout << "Name: Nick\n"
        "Phones: \n"
        "email: ncarmic4@students.kennesaw.edu\n"
        "Hometown: Lawrenceville\n"
        "High School(s): Mountain View High School\n"
        "Previous colleges:\n"
        "List college math / CS courses: Linear Alg, Data Structures, Intro to Databases\n"
        "What, when, and where was your last math and cs course? Comp Org and Arch - Summer 2019, Discrete Math - Spring 2019\n"
        "Type(s) of computers that you are confident working on: Windows and Linux\n"
        "Extracurricular activities(jobs, clubs, sports, etc.): Video games\n"
        "Favorite books, movies, music: Interstellar\n"
        "What you plan to do after graduation ? (Be as specific as you can.): Work full time at current co-op\n" << endl;
}

void exerciseTwo() {
    // declare a num var for user input, and a sum var for the sum of 0+1+2+...n
    int num, sum = 0;

    do {
        // output and ask for user input
        cout << "Enter a Positive Integer:";

        // assign user input to num var
        cin >> num;
    } while (num < 0);

    // add each iteration to the sum
    for (int i = 1; i <= num; i++) {
        sum = sum + i;
    }

    // output sum
    cout << "Sum: " << sum << endl;
}

void exerciseThree() {

    // declare starting num
    int rowStart;

    // ask user for a number and assign to rowStart
    cout << "Enter a number:";
    cin >> rowStart;

    // rowStartNum must be greater than or equal to 0; no negative numbers
    while (rowStart >= 0) {
        // declare nextNum to be the next num in the row
        int nextNum = rowStart;

        // output nextNum, then subtract two. iterate until nextNum <= 0
        while (nextNum >= 0) {
            cout << nextNum << " ";
            nextNum -= 2;
        }

        // row is finished
        cout << endl;
        // decrease rowStart by 2 for the next row
        rowStart -= 2;
    }
}

int main() {
    // declare a num for user input
    int num = 0;

    // do-while loop to select exercise number for convenience
    do {
        cout << "Enter exercise number (1-3):";
        cin >> num;
        cout << endl;

        if (num == 1)
            exerciseOne();
        else if (num == 2)
            exerciseTwo();
        else if (num == 3)
            exerciseThree();

        cout << endl;
    } while (num <= 3 && num >= 1);

    return 0;
}