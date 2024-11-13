//Fadeev Eugene st128225@student.spbu.ru
//This header file contains implementation of vehicle class for assignment 3.

#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>


class Vehicle
{
protected:
    std::string name;
    int speed;

public:
    Vehicle(const std::string& name, int speed);

    const std::string& getName() const;
    const int& getSpeed() const;

    void setName(const std::string& name);
    void setSpeed(int speed);
};

#endif
