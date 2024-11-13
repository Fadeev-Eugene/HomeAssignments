//Fadeev Eugene st128225@student.spbu.ru
//This code contains implementation of dibobot class for assignment 4.


#include <string>
#include <iostream>
#include "Transformer.h"
#include "Dinobot.h"


Dinobot::Dinobot()
    : Transformer(), rank("No rank"), role("No role") {}

Dinobot::Dinobot(const std::string& name, unsigned health, unsigned level, unsigned strength, unsigned perception, const Weapon& weapon, const std::string& rank, const std::string& role)
    : Transformer(name, health, level, strength, perception, weapon), rank(rank), role(role) {}

std::ostream& operator<<(std::ostream& os, const Dinobot& t)
{
    os << "Dinobot: " << t.getName() << "\n"
       << "Health: " << t.getHealth() << "\n"
       << "Level: " << t.getLevel() << "\n"
       << "Strength: " << t.getStrength() << "\n"
       << "Perception: " << t.getPerception() << "\n"
       << "Weapon: " << t.weapon.getType() << " (Damage: " << t.weapon.getDamage() << ") \n"
       << "Rank: " << t.getRank() << "\n"
       << "Role: " << t.getRole() << "\n";
    return os;
}

const std::string& Dinobot::getRank() const
{
    return rank;
}
const std::string& Dinobot::getRole() const
{
    return role;
}

void Dinobot::setRank(const std::string& rank)
{
    this->rank = rank;
}
void Dinobot::setRole(const std::string& role)
{
    this->role = role;
}

bool Dinobot::defend()
{
    return (true);
}
bool Dinobot::heal()
{
    return (true);
}
