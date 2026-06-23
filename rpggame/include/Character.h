#pragma once
#include <string>
class Character{
protected:
    std::string name;
    int health;
    int damage;
public:
    virtual void attack(Character&target) = 0;
    virtual void describe() const = 0;
    virtual void takedamage(int key);
    virtual ~Character();
};