#include <iostream>
#include "LeaugeManager.h"

int main() {
    // 1. Sozdaem igrokov
    Player p1("Иван", "Иванов");
    Player p2("Петр", "Петров");
    Player p3("Сергей", "Сергеев");

    // 2. Sozdaem komandy i dobavlyaem igrokov
    Team team1("Спартак");
    team1.addPlayer(p1);
    team1.addPlayer(p2);

    Team team2("Зенит");
    team2.addPlayer(p3);

    // 3. Sozdaem match (Spartak 2 : 1 Zenit)
    Match match(team1, team2, 2, 1);

    // 4. Dobavlyaem statistiku igrokov v matche
    //    PlayerStats: igrok, goly, pasy
    match.addPlayerStats({p1, 1, 1});   // Ivanov: 1 gol, 1 pas  -> ball = 1*4 + 1 = 5
    match.addPlayerStats({p2, 0, 2});   // Petrov: 0 golov, 2 pasa -> ball = 0 + 2 = 2
    match.addPlayerStats({p3, 2, 0});   // Sergeev: 2 gola, 0 pasov -> ball = 2*4 = 8

    // 5. Sozdaem menedzher, dobavlyaem match
    Leauge league;
    league.addmatch(match);

    // 6. Vybiraem luchshego
    Player best = league.selectbest();

    // 7. Vyvodim rezultat
    std::cout << "Лучший игрок недели: "
              << best.getName() << " " << best.getSurname() << "\n";

    return 0;
}