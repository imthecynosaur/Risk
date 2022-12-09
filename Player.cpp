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
        std::cout << "[PLAYER " << getNumber() << "]: " << "where should troops be deployed, sir ?!" << std::endl;
        showStatus();
        int choice{};
        std::cin >> choice;
        if (choice == 0){
            return;
        }
        if (choice >= territories.size()){
            std::cout << "WRONG TERRITORY !" << std::endl;
            std::cout << std::endl;
            deployTroops(troopsCount);
            return;
        }
        std::cout << "How many troops should be deployed my lord ?!" << std::endl;
        int troopsToBeDeployed {};
        std::cin >> troopsToBeDeployed;
        if (troopsToBeDeployed > troopsCount){
            std::cout << "YOU DON'T HAVE THIS MUCH TROOPS MY LORD !" << std::endl;
            std::cout << std::endl;
            deployTroops(troopsCount);
            return;
        }
        territories[choice-1].setTroops(territories[choice-1].getTroops() + troopsToBeDeployed);
        troopsCount -= troopsToBeDeployed;
    }
    showStatus();
    std::cout << std::endl;
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






