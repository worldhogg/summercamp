#include "Monster.h"
#include <iostream>
Monster::Monster(std::string name, int health, int damage,int expreward){
    this->name = name;
    this->health = health;
    this->damage = damage;
    this->expreward = expreward;
}
int Monster::getexpreward() const{
    return this->expreward;
}
Monster::~Monster(){

};
