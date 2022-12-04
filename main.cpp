#include "Manager.h"

int main() {
    std::cout << "is it still workin ?!" << std::endl;
    Territory germany("Germany", 1);
    germany.show();
    std::cout << germany.getNumber() << std::endl;
    std::cout << germany.getName() << std::endl;
    std::cout << "neighbours: ";
    // std::vector<Territory> germanyNeighbours = germany.getNeighbours();
    for (auto& territory : germany.getNeighbours()){
        territory.show();
    }

    Territory albania("Albania", 2);
    Territory Spain("Spain", 3);
    germany.addNeighbour(albania);
    for (auto& territory : germany.getNeighbours()){
        territory.show();
    }
    germany.addNeighbour(Spain);
    germany.addNeighbour(germany);
    for (auto& territory : germany.getNeighbours()){
        territory.show();
        territory.showAddress();
    }
    std::cout << "albania" << std::endl;
    std::cout << &albania << std::endl;

    Player player1(1);
    Player player2(2);

    player1.addTerritories(germany);
    player2.addTerritories(Spain);
    std::cout << "player 1 territories: " << std::endl;
    player1.showTerritories();
    std::cout << "player 2 territories: " << std::endl;
    player2.showTerritories();

    std::cout << "player and territory is working correctly" << std::endl;

}

