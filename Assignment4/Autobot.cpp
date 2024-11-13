//Fadeev Eugene st128225@student.spbu.ru
//This code contains implementation of autobot class for assignment 4.


#include <string>
#include <iostream>
#include "Transformer.h"
#include "Autobot.h"


Autobot::Autobot()
    : Transformer(), rank("No rank"), role("No role") {}

Autobot::Autobot(const std::string& name, unsigned health, unsigned level, unsigned strength, unsigned perception, const Weapon& weapon, const std::string& rank, const std::string& role)
    : Transformer(name, health, level, strength, perception, weapon), rank(rank), role(role) {}

std::ostream& operator<<(std::ostream& os, const Autobot& t)
{
    os << "Autobot: " << t.getName() << "\n"
       << "Health: " << t.getHealth() << "\n"
       << "Level: " << t.getLevel() << "\n"
       << "Strength: " << t.getStrength() << "\n"
       << "Perception: " << t.getPerception() << "\n"
       << "Weapon: " << t.weapon.getType() << " (Damage: " << t.weapon.getDamage() << ") \n"
       << "Rank: " << t.getRank() << "\n"
       << "Role: " << t.getRole() << "\n";
    return os;
}

const std::string& Autobot::getRank() const
{
    return rank;
}
const std::string& Autobot::getRole() const
{
    return role;
}

void Autobot::setRank(const std::string& rank)
{
    this->rank = rank;
}
void Autobot::setRole(const std::string& role)
{
    this->role = role;
}

bool Autobot::defend()
{
    return (true);
}
bool Autobot::heal()
{
    return (true);
}
