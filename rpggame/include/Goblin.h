#include "Monster.h"
class Goblin:public Monster{
public:
    Goblin() : Monster("Goblin",30,8,20){}
    virtual void attack(Character&target)override;
    virtual void describe()const override;
};