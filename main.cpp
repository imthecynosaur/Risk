#include "Manager.h"

int main() {
    Manager manager;

    manager.startGame(4);
    // manager.showTerritories();
    std::vector<Player> players = {manager.getPlayers()};
    players[1].deployTroops(5);
    
    
}

