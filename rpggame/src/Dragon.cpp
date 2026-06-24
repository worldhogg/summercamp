#include "Dragon.h"
#include <iostream>
void Dragon::attack(Character&target){
    target.takedamage(this->damage);
}
void Dragon::describe()const{
    std::cout << name << " " << health << " " << damage << " " << expreward;
}
    