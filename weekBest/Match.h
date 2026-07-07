#pragma once
#include "Player.h"
#include "Team.h"
#include "PlayerStats.h"
class Match{
private:
    Team team1_;
    Team team2_;
    int goalsTeam1_;
    int goalsTeam2_;
    std::vector<PlayerStats> stat_;
public:
    Match();
    Match(Team team1,Team team2, int goalsTeam1,int goalsTeam2);
    int getGoals1() const;
    int getGoals2() const;
    Team getName1() const;
    Team getName2() const;
    std::vector<PlayerStats>getStats()const;
    void addPlayerStats(PlayerStats p);
};