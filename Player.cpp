#include "Player.h"

Player::Player(int number): number(number) {
}

void Player::addTerritory(Territory& territory){
    territories.push_back(territory);
}

std::vector<Territory> Player::getTerritories(){
    return territories;
}

void Player::showTerritories(){
    for(auto& territory : territories){
        territory.show();
    }
    std::cout << std::endl;
}

int Player::getNumber(){
    return number;
}

bool Player::getTurn(){
    return turn;
}

void Player::setTrun(){
    turn != turn;
}

void Player::deployTroops(int troopsCount){
    while (troopsCount > 0){
        std::cout << "where should troops be deployed, sir ?!" << std::endl;
        showStatus();
        int choice{};
        std::cin >> choice;
        std::cout << "How many troops should be deployed my lord ?!" << std::endl;
        int troopsToBeDeployed {};
        std::cin >> troopsToBeDeployed;
        if (troopsToBeDeployed > troopsCount){
            std::cout << "you don't have this much troops my lord!" << std::endl;
            deployTroops(troopsCount);
            return;
        }
        territories[choice-1].setTroops(territories[choice-1].getTroops() + troopsToBeDeployed);
        troopsCount -= troopsToBeDeployed;
    }
    showStatus();
}

void Player::showStatus(){
    int territoryNumber {1};
    for (auto& territory : territories){
        std::cout << territoryNumber << "- ";
        territory.show();
        std::cout << ": " << territory.getTroops() << std::endl;
        territoryNumber++;
    }
}






