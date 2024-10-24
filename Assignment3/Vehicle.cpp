//Fadeev Eugene st128225@student.spbu.ru
//This code contains implementation of vehicle class for assignment 3.


#include <string>


class Vehicle {
protected:
    std::string name;
    int speed;

public:
    Vehicle(const std::string& name, int speed) : name(name), speed(speed) {}

    const std::string& getName() const { return name; }
    const int& getSpeed() const { return speed; }

    void setName(const std::string& name) {this->name = name; }
    void setSpeed(int speed) { this->speed = speed; }
    
};
