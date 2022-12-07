#include "Manager.h"

Territory& Manager::getTerritoryByName(std::string name){
    for (auto& territory: territories){
        if (territory.getName() == name){
            return territory;
        }
    }
    return territories[0];
}

Territory& Manager::getTerritoryByNumber(int number){
    for (auto& territory: territories){
        if (territory.getNumber() == number){
            return territory;
        }
    }
    return territories[0];
}

void Manager::createPlayer(int count){
    for (size_t i {1}; i <= count; i++){
        Player temp(i);
        players.push_back(temp);
    }
}

void Manager::setBoard(){
    for (auto& continent : continents){
        for (auto& territoryTemplate : continent){
            Territory tempTerritory(territoryTemplate.first, territoryTemplate.second);
            territories.push_back(tempTerritory);
        }
    }

    for (auto& continentNeighbourTemplate : neighbourTemplates){
        for (auto& neighbourTemplate : continentNeighbourTemplate){
            adjustNeighoburs(getTerritoryByName(neighbourTemplate.first), neighbourTemplate.second);
        }
    }
}

void Manager::adjustNeighoburs(Territory& mainTerritory, std::vector<int> neighbourIDs){
    for(int territoryID : neighbourIDs){
        mainTerritory.addNeighbour(getTerritoryByNumber(territoryID));
    }
}

void Manager::showTerritories(){
    for (auto& territory : territories){
        territory.show();
    }
}

std::vector<Player> Manager::getPlayers(){
    return players;
}