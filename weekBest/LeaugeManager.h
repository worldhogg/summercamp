#pragma once
#include "Match.h"
#include "Team.h"
#include "PlayerStats.h"
#include <vector>
class Leauge{
private:
    std::vector<Match>matches_;
public:
    Leauge();
    void addmatch(Match m);
    Player selectbest();
    bool isPlayerInTeam(Player p, Team team);
};