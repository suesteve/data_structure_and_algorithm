#ifndef TEST_VECTOR_H_
#define TEST_VECTOR_H_

#include "vector.h"
#include "../tests/base_test.h"

void TestVector()
{
    Vector<int> vec_i;

    AssertTrue((vec_i.size() == 0), "vector.size()");

    vec_i.push_back(3);

    AssertTrue((vec_i.size() == 1), "vector.size()");

    AssertTrue((vec_i.capacity() == Vector<int>::kSpareCapacity), "vector.capacity()");

    AssertTrue((*vec_i.begin() == 3), "Vector.begin()");

    AssertTrue((*vec_i.end() == 0), "Vector.end()");

    AssertTrue((vec_i.back() == 3), "vector.back()");

    vec_i.push_back(8);

    AssertTrue((vec_i.size() == 2), "vector.size()");

    Vector<int> vec_i2;
    vec_i2 = vec_i;

    AssertTrue((vec_i2.size() == 2), "vector.operator=");

    // expected 3  8
    // TODO(suesteve) use better technique
    for(Vector<int>::iterator i = vec_i2.begin(); i != vec_i2.end(); ++i) {
        std::cout << *i << "  ";
    }

    vec_i.resize(1);

    AssertTrue((vec_i.size() == 1), "vector.resize()");

    vec_i.reserve(80);

    AssertTrue((vec_i.capacity() == 80), "vector.reserve()");

    vec_i.pop_back();

    vec_i.push_back(28);

    AssertTrue(vec_i[0] == 28, "vector.operator[]");

    std::cout
//            << *vec_i.end()
            << std::endl;
}

#endif // TEST_VECTOR_H_!
