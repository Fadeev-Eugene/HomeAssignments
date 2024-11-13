//Fadeev Eugene st128225@student.spbu.ru
//This code contains implementation of dibobot class for assignment 3.


#include <string>
#include <iostream>
#include "Transformer.h"
#include "Dinobot.h"


Dinobot::Dinobot(const std::string& name, unsigned health, unsigned level, unsigned strength, unsigned perception, const Weapon& weapon, const std::string& rank, const std::string& role)
    : Transformer(name, health, level, strength, perception, weapon), rank(rank), role(role) {}

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
