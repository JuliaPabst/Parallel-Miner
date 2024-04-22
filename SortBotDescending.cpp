#include "SortBotDescending.h"
#include "Game.h"

SortBotDescending::SortBotDescending(){
    setBotType(sortingDescending);
};

SortBotDescending::~SortBotDescending() = default;

void SortBotDescending::act(Game& game) {
    vector<vector<vector<int>>> newField = game.getField();

    for (int i = 0; i < game.getX(); i++) {
        for (int j = 0; j < game.getY(); j++) {
            if(i == getPosition()[0] && j == getPosition()[1]){
                std::sort(newField[i][j].begin(), newField[i][j].end(), std::greater<>());
                addPoints(newField[i][j][getPosition()[2]]);
                std::cout << "Descending Bot" << std::endl;
                std::cout << "You get " << newField[i][j][getPosition()[2]] << " points" << std::endl;
                std::cout << "Your total points are now " << getPoints() << std::endl;
                newField[i][j][getPosition()[2]] = 0;
                game.setField(newField);
            }
        }
    }
    std::cout << "\n" << std::endl;

    // test if it sorts correctly
    /*
    for (int i = 0; i < game.getX(); i++) {
        for (int j = 0; j < game.getX(); j++) {
            if(i == getPosition()[0] && j == getPosition()[1]){
                for (int k = 0; k < game.getZ(); k++) {
                        std::cout << newField[i][j][k];
                }
            }
        }
    }
    */

    game.setField(newField);
};