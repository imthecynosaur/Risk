#include "Manager.h"

int main() {
    Manager manager;
    manager.createPlayer(3);

    for (auto& player : manager.getPlayers()){
        int tempNumber = player.getNumber();
        std::cout << "player number " << tempNumber << std::endl;
    }

    manager.setBoard();
    // manager.showTerritories();
    
    std::cout << "this is new" << std::endl;
    while(true){
        int territoryNumber{};
        std::cin >> territoryNumber;
        if (territoryNumber == 0){
            return 0;
        }
        manager.getTerritoryByNumber(territoryNumber).showNeighbours();
    }
}

