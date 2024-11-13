//Fadeev Eugene st128225@student.spbu.ru
//This header file contains implementation of autobot class for assignment 3.


#ifndef AUTOBOT_H
#define AUTOBOT_H

#include <string>
#include <iostream>
#include "Transformer.h"


class Autobot : public Transformer
{
private:
    std::string rank;
    std::string role;

public:
    Autobot(const std::string& name, unsigned health, unsigned level, unsigned strength, unsigned perception, const Weapon& weapon, const std::string& rank, const std::string& role);

    const std::string& getRank() const;
    const std::string& getRole() const;

    void setRank(const std::string& rank);
    void setRole(const std::string& role);

    bool defend();
    bool heal();
};


#endif
