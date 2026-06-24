#include "Goblin.h"
#include <iostream>
void Goblin::attack(Character&target){
    target.takedamage(this->damage);
}
void Goblin::describe() const{
    std::cout << name << " " << health << " " << damage << " " << expreward;
}