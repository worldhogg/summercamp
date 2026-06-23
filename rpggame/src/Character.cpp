#include <iostream>
#include "Character.h"
void Character::takedamage(int key){
    this->health = this->health - key;
}
Character::~Character(){

}
