//Fadeev Eugene st128225@student.spbu.ru
//This code contains implementation of vehicle class for assignment 4.

#include <string>
#include <iostream>
#include "Vehicle.h"


Vehicle::Vehicle(): name("Standart Car"), speed(5) {}

Vehicle::Vehicle(const std::string& name, int speed) : name(name), speed(speed) {}

const std::string& Vehicle::getName() const
{
    return name;
}
const int& Vehicle::getSpeed() const
{
    return speed;
}

void Vehicle::setName(const std::string& name)
{
    this->name = name;
}
void Vehicle::setSpeed(int speed)
{
    this->speed = speed;
}

std::ostream& operator<<(std::ostream& os, const Vehicle& t)
{
    os << "Name: " << t.getName() << "\n"
       << "Speed: " << t.getSpeed();
    return os;
}

bool Vehicle::operator>(const Vehicle& other) const
{
    return speed > other.speed;
}

bool Vehicle::operator<(const Vehicle& other) const
{
    return speed < other.speed;
}



