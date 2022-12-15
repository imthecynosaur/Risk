#include "Player.h"

Player::Player(int number): number(number) {
}

void Player::addTerritory(Territory& territory){
    territories.push_back(territory);
    territoryNumbers.push_back(territory.getNumber());
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
        std::cout << "Remaining troops: " << troopsCount << std::endl;
        std::cout << std::endl;
        std::cout << "[PLAYER " << getNumber() << "]: " << "where should troops be deployed, sir ?!" << std::endl;
        showStatus();
        int choice{};
        std::cin >> choice;
        if (choice == 0){
            return;
        }
        if (choice > territories.size()){
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

int Player::setDraftCount(){
    int draftCount{std::max(3, static_cast<int>(territories.size() / 3))};
    draftCount += checkForContinents();
    return draftCount;
}

int Player::checkForContinents(){
    int continentBouns{};
    for (auto& continent : continentBonusTemplate){
        bool isComplete {true};
        for (int territoryNumber : continent.second){
            if (std::find(territoryNumbers.begin(), territoryNumbers.end(), territoryNumber) == territoryNumbers.end()){
                isComplete = false;
                break;
            }
        
        }
        if (isComplete) {
            int bonus{};
            if (continent.first == "North America"){
                bonus = 5;
            }
            if (continent.first == "South America"){
                bonus = 2;
            }
            if (continent.first == "Europe"){
                bonus = 5;
            }
            if (continent.first == "Africa"){
                bonus = 3;
            }
            if (continent.first == "Asia"){
                bonus = 7;
            }
            if (continent.first == "Australia"){
                bonus = 2;
            }
            continentBouns += bonus;
            std::cout << "getting bonus troops from " << continent.first << std::endl;
        }
    }
    return continentBouns;
}

// bool Player::territoryEquality(Territory& fristTerritroy, Territory& secondTerritory){
//     return (fristTerritroy.getName() == secondTerritory.getName());
// }

bool territoryEquality(Territory& fristTerritroy, Territory& secondTerritory){
    return (fristTerritroy.getName() == secondTerritory.getName());
}

void Player::attack(){
    std::vector<Territory> eligibleTerritories{};
    for (auto& territory : territories){
        if (territory.getTroops() > 1){
            for (auto& neighbourTerritory : territory.getNeighbours()){
                if (std::find(territoryNumbers.begin(), territoryNumbers.end(), neighbourTerritory.getNumber()) == territoryNumbers.end()){
                    eligibleTerritories.push_back(territory);
                    eligibleTerritories.erase(std::unique(eligibleTerritories.begin(), eligibleTerritories.end(), territoryEquality), eligibleTerritories.end());
                    break;

                }
            }
        }
    }

    int counter{1};
    int choice{};

    std::cout << "ELIGIBLE TERRITORIES :" << std::endl;
    for (auto& territory : eligibleTerritories){
        std::cout << counter << "- " << territory.getName() << std::endl;
        counter++;
    }
    std::cout << std::endl;

    std::cin >> choice;
    Territory& chosenTerritory = eligibleTerritories[choice-1];


    std::vector<Territory> availableEnemies{};
    std::cout << "AVAILABLE ENEMIES :" << std::endl;
    counter = 1;
    for (auto& territory : chosenTerritory.getNeighbours()){
        if (std::find(territoryNumbers.begin(), territoryNumbers.end(), territory.getNumber()) == territoryNumbers.end()){
            std::cout << counter << "- " << territory.getName() << std::endl;
            availableEnemies.push_back(territory);
            counter++;
        }
    }
    std::cout << std::endl;
    std::cin >> choice;
    Territory& enemyTerritory = availableEnemies[choice-1];

    std::cout << "attacking " << enemyTerritory.getName() << " from " << chosenTerritory.getName() << std::endl;
}






