#include "Team.h"
Team::Team():
teamName_("Новая команда"){};
Team::Team(std::string teamName):
teamName_(teamName){}
void Team::addPlayer(Player p){
    players_.push_back(p);
}
std::vector<Player> Team::getPlayers()const{
    return players_;
}
std::string Team::getTeamName() const{
    return teamName_;
}

