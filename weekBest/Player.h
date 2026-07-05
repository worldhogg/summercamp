#pragma once
#include <string>
class Player{
private:
    std::string name_;
    std::string surname_;
public:
    Player();
    Player(std::string name,std::string surname);
    ~Player();
    std::string getName() const;
    std::string getSurname() const;
};