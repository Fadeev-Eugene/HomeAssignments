//Fadeev Eugene st128225@student.spbu.ru
//This file contains implementation of test classes for assignment 6.


#ifndef Classes_H
#define Classes_H

#include <iostream>
#include <vector>

class Class1
{
public:
    bool bar(int num, std::vector<float>& vec)
    {
        return num > 0;
    }

    int c_1_1()
    {
        return 42;
    }
    float c_1_2()
    {
        return 3.14f;
    }
    void c_1_3()
    {
        std::cout << "Class1::c_1_3() called\n";
    }
};

class Class2
{
public:
    bool bar(int num, std::vector<float>& vec)
    {
        return !vec.empty();
    }

    int c_2_1()
    {
        return 100;
    }
    float c_2_2()
    {
        return 2.71f;
    }
    void c_2_3()
    {
        std::cout << "Class2::c_2_3() called\n";
    }
};

class Class3
{
public:
    bool bar(int num, std::vector<float>& vec)
    {
        return num == -static_cast<int>(vec.size());
    }

    int c_3_1()
    {
        return -1;
    }
    float c_3_2()
    {
        return 1.618f;
    }
    void c_3_3()
    {
        std::cout << "Class3::c_3_3() called\n";
    }
};

#endif
