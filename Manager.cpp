#include "Manager.h"

void Manager::startGame(int playerCount){
    createPlayer(playerCount);
    setBoard();
    distributeTerritories();
    // deployTroops();
    gameLoop();
}

void Manager::gameLoop(){
    while(!winCondition){
        for (auto& player : players){
            player.deployTroops(player.setDraftCount());
        }
    }
}

void Manager::deployTroops(){
    int initialTroops{};
    switch (players.size())
    {
        case 2:
            initialTroops = 5;
            break;
        case 3:
            initialTroops = 35;
            break;

        case 4:
            initialTroops = 30;
            break;
        
        case 5:
            initialTroops = 25;
            break;
        
        default:
            break;
    }

    while (initialTroops > 0){
        for (auto& player : players){
            std::cout << "PLAYER NUMBER " << player.getNumber() << ":" << std::endl;
            std::cout << std::endl;
            player.deployTroops(std::min(3, initialTroops));
        }
        initialTroops -= std::min(3, initialTroops);
    }
}

void Manager::distributeTerritories(){
    std::vector<int> territoryIDs{};
    for (auto& continent : continents){
        for (auto& territory : continent){
            territoryIDs.push_back(territory.second);
        }
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(territoryIDs.begin(), territoryIDs.end(), g);
    
    for (size_t i{1}; i <= 42; i++){
        players[i % players.size()].addTerritory(getTerritoryByNumber(territoryIDs[i-1]));
    }
}

int Manager::generateRandomNumber(int begin, int end){
    std::random_device seeder;
    const auto seed {seeder.entropy() ? seeder() : time(nullptr)};
    std::mt19937 engine {static_cast<std::mt19937::result_type>(seed)};
    std::uniform_int_distribution<int> distribution {begin, end};
    return distribution(engine);
}



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