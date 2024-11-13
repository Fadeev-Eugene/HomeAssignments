//Fadeev Eugene st128225@student.spbu.ru
//This code contains implementation of decepticon class for assignment 3.


#include <string>
#include <iostream>
#include "Transformer.h"
#include "Decepticon.h"


Decepticon::Decepticon(const std::string& name, unsigned health, unsigned level, unsigned strength, unsigned perception, const Weapon& weapon, const std::string& rank, const std::string& role)
    : Transformer(name, health, level, strength, perception, weapon), rank(rank), role(role) {}

const std::string& Decepticon::getRank() const
{
    return rank;
}
const std::string& Decepticon::getRole() const
{
    return role;
}

void Decepticon::setRank(const std::string& rank)
{
    this->rank = rank;
}
void Decepticon::setRole(const std::string& role)
{
    this->role = role;
}

bool Decepticon::defend()
{
    return (true);
}
bool Decepticon::heal()
{
    return (true);
}
