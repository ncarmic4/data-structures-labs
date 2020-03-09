#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include "node2.h"
#include "bag5.h"

using namespace std;

int main()
{
    bag<int> b1;
    b1.insert(7);
    b1.insert(6);
    b1.insert(5);
    b1.insert(4);
    b1.insert(3);
    b1.insert(2);
    b1.insert(1);

    cout << "----------------------" << endl;
    b1.print_value_range(2, 5);
    cout << "----------------------" << endl;
    b1.print_value_range(2, 78);
    cout << "----------------------" << endl;
    b1.print_value_range(2, 1);
    cout << "----------------------" << endl;
    b1.print_value_range(8, 5);

    cout << endl << endl << endl;
    bag<int> b2;
    b2.insert(1);
    b2.insert(2);
    b2.insert(3);
    b2.insert(4);
    b2.insert(5);
    b2.insert(6);
    b2.insert(5);
    b2.insert(4);
    b2.insert(3);
    b2.insert(2);
    b2.insert(1);
    cout << "Bag before removing repetitions: " << endl;
    b2.print();
    cout << "Bag after removing repetitions: " << endl;
    b2.remove_repetitions();
    b2.print();

    return EXIT_SUCCESS;
}
