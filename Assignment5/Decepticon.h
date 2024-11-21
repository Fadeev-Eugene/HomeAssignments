//Fadeev Eugene st128225@student.spbu.ru
//This header file contains implementation of decepticon class for assignment 5.


#ifndef DECEPTICON_H
#define DECEPTICON_H

#include <string>
#include <iostream>
#include "Transformer.h"


class Decepticon : public Transformer
{
private:
    std::string rank;
    std::string role;

public:
    Decepticon();

    Decepticon(const std::string& name, unsigned health, unsigned level, unsigned strength, unsigned perception, const Weapon& weapon, const std::string& rank, const std::string& role);

    friend std::ostream& operator<<(std::ostream& os, const Decepticon& t);

    const std::string& getRank() const;
    const std::string& getRole() const;

    void setRank(const std::string& rank);
    void setRole(const std::string& role);
    
    void transform() const override;
    void openFire() const override;
    void ulta() const override;

    bool defend();
    bool heal();
};


#endif
