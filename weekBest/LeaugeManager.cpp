#include "LeaugeManager.h"
#include <unordered_map>
#include <string>

Leauge::Leauge(){};

void Leauge::addmatch(Match m){
    matches_.push_back(m);
}

bool Leauge::isPlayerInTeam(Player p, Team team){
    for (auto player : team.getPlayers()){
        if (player.getName() == p.getName() && player.getSurname() == p.getSurname()){
            return true;
        }
    }
    return false;
}

Player Leauge::selectbest(){
    std::unordered_map<std::string,int> scores;
    std::unordered_map<std::string,Player> result;

    // 1. Накопление баллов по голам и пасам
    for (auto match : matches_){
        for (auto stat : match.getStats()){
            int ball = stat.goals * 4 + stat.asissts * 1;
            std::string name = stat.player.getName() + " " + stat.player.getSurname();
            scores[name] += ball;
            result[name] = stat.player;
        }
    }

    // 2. Добавляем +5 за победу команды игрока
    for (auto match : matches_){
        for (auto stat : match.getStats()){
            std::string name = stat.player.getName() + " " + stat.player.getSurname();
            if (match.getGoals1() > match.getGoals2()){
                if (isPlayerInTeam(stat.player, match.getName1())){
                    scores[name] += 5;
                }
            }
            else if (match.getGoals2() > match.getGoals1()){
                if (isPlayerInTeam(stat.player, match.getName2())){
                    scores[name] += 5;
                }
            }
        }
    }

    // 3. Поиск игрока с максимальным баллом
    int maxscore = 0;
    std::string maxplayer = "";
    for (auto player : scores){
        if (player.second > maxscore){
            maxscore = player.second;
            maxplayer = player.first;
        }
    }

    return result[maxplayer];
}