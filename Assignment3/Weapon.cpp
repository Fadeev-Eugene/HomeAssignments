//Fadeev Eugene st128225@student.spbu.ru
//This code contains implementation of weapon class for assignment 3.


#include <string>


class Weapon {
protected:
    std::string type;
    int damage;
    
public:
    Weapon(const std::string& type, int damage) : type(type), damage(damage) {}

    const std::string& getType() const { return type; }
    const int& getDamage() const { return damage; }

    void setType(const std::string& type) { this->type = type; }
    void setDamage(int damage) { this->damage = damage; }
};

