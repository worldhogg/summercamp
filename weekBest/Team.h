#pragma once
#include "Player.h"
#include <vector>
class Team{
private:
    std::string teamName_;
    std::vector<Player>players_;
public:
    Team();
    Team(std::string Teamname);
    void addPlayer(Player p);
    std::vector<Player> getPlayers() const;
    std::string getTeamName() const;
};