//Fadeev Eugene st128225@student.spbu.ru
//This header file contains implementation of transformer class for assignment 3.


#ifndef TRANSFORMER_H
#define TRANSFORMER_H

#include <string>
#include <iostream>
#include "Vehicle.h"
#include "Weapon.h"



class Transformer {
protected:
    std::string name;
    unsigned health;
    unsigned level;
    
    unsigned strength;
    unsigned perception;
        
    Weapon weapon;
    Vehicle* vehicle;

public:
    Transformer(const std::string& name, unsigned health, unsigned level, unsigned strength, unsigned perception, const Weapon& weapon)
        :name(name), health(health), level(level), weapon(weapon), strength(strength), perception(perception), vehicle(nullptr) 
    {
        std::cout << "Transformer " << name << " is created." << std::endl;
    }
    
    ~Transformer(){
        std::cout << "Transformer " << name << " is destroyed." << std::endl;
    }
    
    const std::string& getName() const { return name; }
    const unsigned& getHealth() const { return health; }
    const unsigned& getLevel() const { return level; }
    const unsigned& getStrength() const { return strength; }
    const unsigned& getPerception() const { return perception; }
    const Weapon& getWeapon() const { return weapon; }
    const Vehicle* getVehicle() const { return vehicle; }
    
    void setName(const std::string& name) { this->name = name; }
    void setHealth(unsigned health) { this->health = health; }
    void setLevel(unsigned level) { this->level = level; }
    void setStrength(unsigned strength) { this->strength = strength; }
    void setPerception(unsigned perception) { this->perception = perception; }
    void setWeapon(const Weapon& weapon) { this->weapon = weapon; }
    void assignVehicle(Vehicle* v) { vehicle = v; }
    
    bool transform() {
        return (true);
    }
    
    bool attack() {
        return (true);
    }
};

#endif
