#include <cstdlib>;
#include <iostream>

using namespace std;

void exerciseOne() {
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
    int num, sum = 0;

    do {
        cout << "Enter a Positive Integer:";
        cin >> num;
    } while (num < 0);

    for (int i = 1; i <= num; i++) {
        sum = sum + i;
    }

    cout << "Sum: " << sum << endl;
}

void exerciseThree() {

    int rowStartNum;

    cout << "Enter a number:";
    cin >> rowStartNum;

    while (rowStartNum >= 0) {

        int nextNum = rowStartNum;
        while (nextNum >= 0) {
            cout << nextNum << " ";
            nextNum -= 2;
        }
        cout << endl;
        rowStartNum -= 2;
    }
}

int main() {
    
    int num = 0;
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
        else
            break;
    } while (num <= 3 && num >= 1);

    return 0;
}