//Fadeev Eugene st128225@student.spbu.ru
//This file contains implementation of tests for assignment 6.


#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "MyTemplate.h"
#include "Classes.h"


TEST(Class1Test, ExpectTrue)
{
    std::vector<float> v = {1.0f, 2.0f};
    Class1 c1;
    MyTemplate<Class1> t(c1, 10, v);

    EXPECT_TRUE(t.foo());
}

TEST(Class1Test, ExpectFalse)
{
    std::vector<float> v = {1.0f, 2.0f};
    Class1 c1;
    MyTemplate<Class1> t(c1, -10, v);

    EXPECT_FALSE(t.foo());
}

TEST(Class2Test, ExpectTrue)
{
    std::vector<float> v = {1.0f, 2.0f};
    Class2 c2;
    MyTemplate<Class2> t(c2, 10, v);

    EXPECT_TRUE(t.foo());
}

TEST(Class2Test, ExpectFalse)
{
    std::vector<float> v = {};
    Class2 c2;
    MyTemplate<Class2> t(c2, 10, v);

    EXPECT_FALSE(t.foo());
}

TEST(Class3Test, ExpectTrue)
{
    std::vector<float> v = {1.0f, 2.0f};
    Class3 c3;
    MyTemplate<Class3> t(c3, -2, v);

    EXPECT_TRUE(t.foo());
}

TEST(Class3Test, ExpectFalse)
{
    std::vector<float> v = {1.0f, 2.0f};
    Class3 c3;
    MyTemplate<Class3> t(c3, 2, v);

    EXPECT_FALSE(t.foo());
}

TEST(IntTest, ExpectTrue)
{
    int i = 0;
    MyTemplate<int> t(i);

    EXPECT_TRUE(t.foo());
}

TEST(DoubleTest, ExpectFalse)
{
    double d = 1.1;
    MyTemplate<double> t(d);

    EXPECT_FALSE(t.foo());
}







