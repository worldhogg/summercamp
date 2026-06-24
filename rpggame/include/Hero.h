#pragma once
#include <string>
#include "Character.h"
#include <iostream>
class Hero : public Character{
public:
    Hero(std::string name,int health, int damage);
    void attack(Character&target)override;
    void describe() const override;
};