#ifndef SIMPLE_TEST_H_
#define SIMPLE_TEST_H_

#include <iostream>

void AssertTrue(bool test, std::string info)
{
    if(!test) {
        std::cerr
            << "Error occur when testing: "
            << info
            << std::endl;
    }
}

void AssertFalse(bool test)
{
    return;
}

#endif // SIMPLE_TEST_H_
