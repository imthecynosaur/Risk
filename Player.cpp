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
        std::cout << std::endl;
    }
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




