//Fadeev Eugene st128225@student.spbu.ru
//This code contains implementation of weapon class for assignment 4.


#include <string>
#include <iostream>
#include "Weapon.h"

Weapon::Weapon(): type("Standart gun"), damage(5) {}

Weapon::Weapon(const std::string& type, int damage) : type(type), damage(damage) {}

const std::string& Weapon::getType() const
{
    return type;
}
const int& Weapon::getDamage() const
{
    return damage;
}

void Weapon::setType(const std::string& type)
{
    this->type = type;
}
void Weapon::setDamage(int damage)
{
    this->damage = damage;
}

std::ostream& operator<<(std::ostream& os, const Weapon& t)
{
    os << "Type: " << t.getType() << "\n"
       << "Damage: " << t.getDamage();
    return os;
}

bool Weapon::operator>(const Weapon& other) const
{
    return damage > other.damage;
}

bool Weapon::operator<(const Weapon& other) const
{
    return damage < other.damage;
}
