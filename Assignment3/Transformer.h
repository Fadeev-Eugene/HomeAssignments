//Fadeev Eugene st128225@student.spbu.ru
//This header file contains implementation of transformer class for assignment 3.

#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>
#include <iostream>
#include "Vehicle.h"
#include "Weapon.h"
#include <iostream>

class Transformer
{
protected:
    std::string name;
    unsigned health;
    unsigned level;

    unsigned strength;
    unsigned perception;

    Weapon weapon;
    Vehicle* vehicle;

public:
    Transformer(const std::string& name, unsigned health, unsigned level, unsigned strength, unsigned perception, const Weapon& weapon);

    ~Transformer();

    const std::string& getName() const;
    const unsigned& getHealth() const;
    const unsigned& getLevel() const;
    const unsigned& getStrength() const;
    const unsigned& getPerception() const;
    const Weapon& getWeapon() const;
    const Vehicle* getVehicle() const;

    void setName(const std::string& name);
    void setHealth(unsigned health);
    void setLevel(unsigned level);
    void setStrength(unsigned strength);
    void setPerception(unsigned perception);
    void setWeapon(const Weapon& weapon);
    void assignVehicle(Vehicle* v);

    bool transform();

    bool attack();
};

#endif
