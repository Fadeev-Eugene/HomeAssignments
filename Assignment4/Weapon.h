//Fadeev Eugene st128225@student.spbu.ru
//This header file contains implementation of weapon class for assignment 4.


#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class Weapon
{
protected:
    std::string type;
    int damage;

public:
    Weapon();

    Weapon(const std::string& name, int damage);

    const std::string& getType() const;
    const int& getDamage() const;

    void setType(const std::string& name);
    void setDamage(int speed);

    friend std::ostream& operator<<(std::ostream& os, const Weapon& t);

    bool operator>(const Weapon& other) const;

    bool operator<(const Weapon& other) const;
};


#endif
