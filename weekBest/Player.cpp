#include "Player.h"
#include <string>
Player::Player(){
    name_ = "Не заполнено";
    surname_ = "Не заполнено";
}
Player::Player(std::string name,std::string surname):
name_(name),surname_(surname){}
Player::~Player(){
}
std::string Player::getName()const{
    return name_;
}
std::string Player::getSurname()const{
    return surname_;
}

