#pragma once
#include <string>
#include <vector>
#include <iostream>

class Territory{
    public:
        Territory(std::string, int);
        std::string getName();
        int getNumber();
        std::vector<Territory> getNeighbours();
        void show();
        void addNeighbour(Territory&);
        void showAddress();
        void setTroops(int);
        int getTroops();
        void showNeighbours();

    private:
        std::string name;
        int number;
        int troops;
        std::vector<Territory> neighbours;

};