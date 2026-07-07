#include "Match.h"
Match::Match():
team1_("Команда 1"),team2_("Команда 2"),goalsTeam1_(0),goalsTeam2_(0){}
Match::Match(Team team1,Team team2, int goalsTeam1,int goalsTeam2):
team1_(team1),team2_(team2),goalsTeam1_(goalsTeam1),goalsTeam2_(goalsTeam2){}
int Match::getGoals1()const{
    return goalsTeam1_;
}
int Match::getGoals2()const{
    return goalsTeam2_;
}
Team Match::getName1()const{
    return team1_;
}
Team Match::getName2()const{
    return team2_;
}
std::vector<PlayerStats> Match::getStats()const{
    return stat_;
}
void Match::addPlayerStats(PlayerStats p){
    stat_.push_back(p);
}