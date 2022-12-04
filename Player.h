#include "Territory.h"

class Player{
    public:
        Player(int);
        void addTerritories(Territory&);
        std::vector<Territory> getTerritories();
        void showTerritories();
        int getNumber();
        bool getTurn();
        void setTrun();

    private:
        int number;
        bool turn {false};
        std::vector<Territory> territories;
        
};