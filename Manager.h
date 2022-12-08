#include <unordered_map>
#include <random>
#include <algorithm>
#include <optional>
#include "Player.h"



class Manager {
    public:
        void startGame(int);
        void showTerritories();
        std::vector<Player> getPlayers();
        

    private:
        std::vector<Player> players;
        std::vector<Territory> territories;
        void adjustNeighoburs(Territory&, std::vector<int>);
        void createPlayer(int);
        void setBoard();
        void distributeTerritories();
        int generateRandomNumber(int, int);
        Territory& getTerritoryByName(std::string);
        Territory& getTerritoryByNumber(int);






        const std::unordered_map<std::string, int> NorthAmerica {{"Alaska", 11}, {"Northwest Territory", 16}, {"GreenLand", 15},
        {"Alberta", 12}, {"Ontario", 17}, {"Quebec", 18}, {"Western US", 19}, {"Eastern US", 14}, {"Central America", 13},};

        const std::unordered_map<std::string, int> SouthAmerica {{"Venezuela", 24}, {"Brazil", 22},
        {"Peru", 23}, {"Argentina", 21}};

        const std::unordered_map<std::string, int> Europe {{"IceLand", 32}, {"Scandinavia", 34},
        {"Great Britain", 31}, {"Northern Europe", 33}, {"Ukraine", 36}, {"Western Europe" , 37},
        {"Southern Europe", 35}};

        const std::unordered_map<std::string, int> Africa {{"North Africa", 45}, {"Egypt", 43},
        {"Congo", 41}, {"East Africa", 42}, {"South Africa", 46}, {"Madagascar", 44}};

        const std::unordered_map<std::string, int> Asia {{"Yakutsk", 512}, {"Ural", 511},
        {"Siberia", 510}, {"Irkutsk", 54}, {"Kamchatka", 56}, {"Afghanistan", 51},
        {"China", 52}, {"Mongolia", 58}, {"Japan", 55}, {"Middle east", 57},
        {"India", 53}, {"Siam", 59}};

        const std::unordered_map<std::string, int> Australia {{"Indonesia", 62}, {"New Guinea", 63},
        {"Western Australia", 64}, {"Eastern Australia", 61}};



        const std::unordered_map<std::string, std::vector<int>> NorthAmericaNeighbourTemplate {{"Alaska", {12, 16, 56}}, {"Northwest Territory", {11, 12, 15, 17}},
        {"GreenLand", {16, 17, 18, 32}}, {"Alberta", {11, 17, 19}}, {"Ontario", {12, 14, 15, 16, 18, 19}}, {"Quebec", {15, 17, 14}}, {"Western US",{12, 13, 14, 17}},
        {"Eastern US", {17, 18, 19, 13}}, {"Central America", {19, 14, 24}}};

        const std::unordered_map<std::string, std::vector<int>> SouthAmericaNeighbourTemplate {{"Venezuela", {13, 22, 23}}, {"Brazil", {24, 23, 21, 45}},
        {"Peru", {24, 22, 21}}, {"Argentina", {22, 23, 24}}};

        const std::unordered_map<std::string, std::vector<int>> EuropeNeighbourTemplate {{"IceLand", {15, 31, 34}}, {"Scandinavia", {31, 32, 33, 36}},
        {"Great Britain", {32, 33, 34, 37}}, {"Northern Europe", {31, 34, 35, 36, 37}}, {"Ukraine", {33, 34, 35, 511, 51, 57}}, {"Western Europe" , {31, 33, 35, 45}},
        {"Southern Europe", {36, 37, 45, 43, 57}}};

        const std::unordered_map<std::string, std::vector<int>> AfricaNeighbourTemplate {{"North Africa", {22, 37, 35, 42, 41, 43}}, {"Egypt", {35, 42, 45, 57}},
        {"Congo",{45, 42, 46}}, {"East Africa", {41, 43, 46, 44, 57}}, {"South Africa", {41, 42, 44}}, {"Madagascar", {42, 46}}};

        const std::unordered_map<std::string, std::vector<int>> AsiaNeighbourTemplate {{"Yakutsk", {510, 54, 56}}, {"Ural", {36, 51, 52, 510}},
        {"Siberia", {52, 54, 58, 511, 512}}, {"Irkutsk", {56, 58, 510, 512}}, {"Kamchatka", {11, 54, 58, 55, 512}}, {"Afghanistan", {53, 52, 511, 57, 36}},
        {"China", {51, 53, 58, 59, 510}}, {"Mongolia", {52, 54, 56, 55, 510}}, {"Japan", {56, 58}}, {"Middle east", {36, 35, 43, 42, 51, 53}},
        {"India", {51, 52, 57, 59}}, {"Siam", {52, 53, 62}}};

        const std::unordered_map<std::string, std::vector<int>> AustraliaNeighbourTemplate {{"Indonesia", {63, 64, 59}}, {"New Guinea", {62, 64, 61}},
        {"Western Australia", {62, 63, 61}}, {"Eastern Australia", {63, 64}}};






        const std::vector<std::unordered_map<std::string, int>> continents{NorthAmerica,
        SouthAmerica, Europe, Africa, Asia, Australia}; 

        const std::vector<std::unordered_map<std::string, std::vector<int>>> neighbourTemplates{
            NorthAmericaNeighbourTemplate, SouthAmericaNeighbourTemplate, EuropeNeighbourTemplate,
            AfricaNeighbourTemplate, AsiaNeighbourTemplate, AustraliaNeighbourTemplate};
};