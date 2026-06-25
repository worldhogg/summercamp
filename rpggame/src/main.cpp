#include "Hero.h"
#include "Goblin.h"
#include "Dragon.h"
#include <vector>
#include <iostream>
#include <memory>
void battle(Character*a,Character*b){
    int round = 1;
    while (a->isalive() && b->isalive()){
        std::cout << "Раунд " << round << std::endl;
        std::cout << a->getname() << " атакует " << b->getname() << std::endl;
        a->attack(*b);
        std::cout << std::endl;
        if (b->isalive()){
            std::cout << b->getname() << " атакует " << a->getname();
            std::cout << std::endl;
            b->attack(*a);
        }
        else{
            break;
        }
        std :: cout << std::endl;
        if (!a->isalive()){
            break;
        }
        a->describe();
        std::cout << std::endl;
        b->describe();
        std::cout << std::endl;
        round++;

    }
    if (a->isalive()) {
        std::cout << "Победил " << a->getname() << "!\n";
}   else {
        std::cout << "Победил " << b->getname() << "!\n";
}
}
int main() {
    std::vector<std::unique_ptr<Character>>participants;
    participants.push_back(std::make_unique <Hero>("Артём", 100, 20));
    participants.push_back(std::make_unique <Goblin>());
    participants.push_back(std::make_unique <Dragon>());
    participants.push_back(std::make_unique <Hero>("Кашед",100,20));
    battle(participants[0].get(),participants[1].get());
    battle(participants[3].get(),participants[2].get());

}