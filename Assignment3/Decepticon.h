//Fadeev Eugene st128225@student.spbu.ru
//This header file contains implementation of decepticon class for assignment 3.


#ifndef AUTOBOT_H
#define AUTOBOT_H

#include <string>
#include "Transformer.h"


class Decepticon : public Transformer {
private:
    std::string rank;
    std::string role;

public:
    Decepticon(const std::string& name, unsigned health, unsigned level, unsigned strength, unsigned perception, const Weapon& weapon, const std::string& rank, const std::string& role)
        : Transformer(name, health, level, strength, perception, weapon), rank(rank), role(role){
    }

    const std::string& getRank() const { return rank; }
    const std::string& getRole() const { return role; }
    
    void setRank(const std::string& rank) { this->rank = rank; }
    void setRole(const std::string& role) { this->role = role; }

    bool defend() { return (true); }
    bool heal() { return (true); }
};
#endif 
