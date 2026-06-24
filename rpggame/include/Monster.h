#pragma once
#include "Character.h"
#include <iostream>
class Monster:public Character{
protected:
    int expreward;
public:
    Monster(std::string name, int health, int damage,int expreward);
    int getexpreward()const;
    virtual ~Monster();
};