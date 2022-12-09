#include "Territory.h"

class Player{
    public:
        Player(int);
        void addTerritory(Territory&);
        std::vector<Territory> getTerritories();
        void showTerritories();
        int getNumber();
        bool getTurn();
        void setTrun();
        void deployTroops(int);
        void showStatus();

    private:
        int number;
        bool turn {false};
        std::vector<Territory> territories;
};