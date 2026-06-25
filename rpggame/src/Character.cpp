#include <iostream>
#include "Character.h"
void Character::takedamage(int key){
    this->health = this->health - key;
}
Character::~Character(){

}
bool Character::isalive() const{
    if (health > 0){
        return true;
    }
    return false;
}
std::string Character::getname()const{
    return this->name;
}
