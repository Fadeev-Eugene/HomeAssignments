//Fadeev Eugene st128225@student.spbu.ru
//This code contains implementation of autobot class for assignment 3.


#include <string>
#include "Transformer.h"


class Autobot : public Transformer {
private:
    std::string rank;
    std::string role;

public:
    Autobot(const std::string& name, unsigned health, unsigned level, unsigned strength, unsigned perception, const Weapon& weapon, const std::string& rank, const std::string& role)
        : Transformer(name, health, level, strength, perception, weapon), rank(rank), role(role){
    }

    const std::string& getRank() const { return rank; }
    const std::string& getRole() const { return role; }
    
    void setRank(const std::string& rank) { this->rank = rank; }
    void setRole(const std::string& role) { this->role = role; }

    bool defend() { return (true); }
    bool heal() { return (true); }
};

