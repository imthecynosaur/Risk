#include <unordered_map>
#include <algorithm>
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
        int setDraftCount();
        int checkForContinents();

    private:
        int number;
        bool turn {false};
        std::vector<Territory> territories;
        std::vector<int> territoryNumbers;

        const std::unordered_map<std::vector<int>, int> continentBonusTemplate {{{11, 12, 13, 14, 15, 16, 17, 18 , 19}, 5},
        {{61, 62, 63, 64}, 2}, {{51, 52, 53, 54, 55, 56, 57, 58, 59, 510, 511, 512}, 7},
        {{41, 42, 43, 44, 45, 46}, 3}, {{31, 32, 33, 34, 35, 36, 37}, 5}, {{21, 22, 23, 24}, 2}};





        // const std::unordered_map<std::vector<int>, int> NorthAmerica {{{11, 12, 13, 14, 15, 16, 17, 18 , 19}, 5}};
        // const std::unordered_map<std::vector<int>, int> SouthAmerica {{{21, 22, 23, 24}, 2}};
        // const std::unordered_map<std::vector<int>, int> Eruope {{{31, 32, 33, 34, 35, 36, 37}, 5}};
        // const std::unordered_map<std::vector<int>, int> Africa {{{41, 42, 43, 44, 45, 46}, 3}};
        // const std::unordered_map<std::vector<int>, int> Asia{{{51, 52, 53, 54, 55, 56, 57, 58, 59, 510, 511, 512}, 7}};
        // const std::unordered_map<std::vector<int>, int> Australia {{{61, 62, 63, 64}, 2}};
        // const std::vector<std::unordered_map<std::vector<int>, int>> continents{NorthAmerica, SouthAmerica, Europe, Africa, Asia, Australia};
};