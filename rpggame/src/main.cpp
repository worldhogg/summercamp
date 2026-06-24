#include "Hero.h"
#include "Goblin.h"
#include "Dragon.h"
#include <vector>
#include <iostream>

int main() {
    std::vector<Character*> participants;
    participants.push_back(new Hero("Артём", 100, 20));
    participants.push_back(new Goblin());
    participants.push_back(new Dragon());

    for (Character* c : participants){
        c->describe();
        std::cout << "\n";
    }
    participants[0]->attack(*participants[1]);
    std::cout << "Герой атакует гоблина ";
    participants[1]->describe();
    

    // 3. ОБЯЗАТЕЛЬНО почистить: пройти циклом и delete каждого
    for (Character* c : participants) {
        delete c;   // виртуальный деструктор → правильная цепочка для каждого типа
    }
}