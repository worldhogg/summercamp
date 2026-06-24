#include "Monster.h"
class Dragon:public Monster{
public:
    Dragon():Monster("Dragon",200,40,100){};
    virtual void attack(Character&target)override;
    virtual void describe()const override;
};