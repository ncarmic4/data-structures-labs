#include <iostream>
#include "set.h"

int main(int argc, char **argv)
{
    bool testvalue = false;
    set s(5);
    testvalue = s.insert (7);
    if(testvalue == false){
        std::cout << "member function 'insert' returned false" << std::endl;
        return 0;
    }
    std::cout << "Set s contains " << s << std::endl;
    std::cout << " --> must contains [7] " << std::endl;
    testvalue = s.insert (8);
    std::cout << "Set s contains " << s << std::endl;
    std::cout << " --> must contains [7 8] " << std::endl;
    testvalue = s.insert(3);
    std::cout << "Set s contains " << s << std::endl;
    std::cout << " --> must contains [7 8 3] " << std::endl;
    testvalue = s.insert (2);
    testvalue = s.insert (1);
    testvalue = s.insert (22);
    std::cout << "Set s contains " << s << std::endl;
    std::cout << " --> must contains [7 8 3 2 1 22] " << std::endl <<std::endl;
    
    set s1(s);
    std::cout << "Set s1 contains " << s1 << "(Test for the copy constructor)" << std::endl;
    std::cout << " --> must contains [7 8 3 2 1 22] " << std::endl<< std::endl;
    set s2 (78);
    s2 = s;
    std::cout << "Set s2 contains " << s2 << "(Test for the assign operator)" <<std::endl;
    std::cout << " --> must contains [7 8 3 2 1 22] " << std::endl;
    
    std::cout << std::endl << std::endl;
    testvalue = s2.erase(1);
    if(testvalue == false){
        std::cout << "member function 'erase' returned false" << std::endl;
        return 0;
    }
    std::cout << "After erase the number 1." << std::endl << s2 << std::endl <<" --> must contains [7 8 3 2 22] "   << std::endl;
    std::cout << std::endl;
    testvalue =  s2.erase(22);
    std::cout << "After erase the number 22." << std::endl << s2 << std::endl <<" --> must contains [7 8 3 2] "   << std::endl;


    std::cout << std::endl << std::endl;
    
    set s3 (10);
    testvalue = s3.insert(50);
    testvalue = s3.insert(51);
    testvalue = s3.insert(52);
    testvalue = s3.insert(7);
    testvalue = s3.insert(8);
    testvalue = s3.insert(9);
    testvalue = s3.insert(10);
    
    std::cout << "Set s3 contains " << s3 << "(Test for the += operator)" <<std::endl;
    std::cout << " --> must contains [50 51 52 7 8 9 10] " << std::endl << std::endl;

    s3 += s;
    
    std::cout << "Set [s3 + s] contains " << s3 << "(Test for the += operator)" <<std::endl;
    std::cout << " --> must contains [50 51 52 7 8 9 10 3 2 1 22]" << std::endl << std::endl;
    std::cout << "Done!" << std::endl;
    return 0;
}