#include "Hero.h"
#include <iostream>
Hero::Hero(std::string name,int damage, int health){
        this->name = name;
        this->damage = damage;
        this->health = health;
}
void Hero::attack(Character&target){
    target.takedamage(this->damage);
}
void Hero::describe() const{
    std::cout << name << " " << damage << " " << health;
}