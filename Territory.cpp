#include "Territory.h"

Territory::Territory(std::string name, int number): name(name), number(number){}

std::string Territory::getName(){
    return name;
}

int Territory::getNumber(){
    return number;
}

std::vector<Territory> Territory::getNeighbours(){
    return neighbours;
}

void Territory::show(){
    std::cout << name << "  ";
}

void Territory::addNeighbour(Territory& territory){
    neighbours.push_back(territory);
}

void Territory::showAddress(){
    std::cout << this << std::endl;
}

void Territory::setTroops(int value){
    troops = value;
}

int Territory::getTroops(){
    return troops;
}

void Territory::showNeighbours(){
    std::cout << "showing neighbours for " << name << std::endl;
    for(auto& territory : neighbours){
        territory.show();
    }
}
