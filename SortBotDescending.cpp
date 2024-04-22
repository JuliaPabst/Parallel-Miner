#include "SortBotDescending.h"
#include "Game.h"

SortBotDescending::SortBotDescending(){
    setBotType(sortingDescending);
};

SortBotDescending::~SortBotDescending() = default;

void SortBotDescending::act(Game& game, std::mutex& m) {
    vector<vector<vector<int>>> newField = game.getField();

    for (int i = 0; i < game.getX(); i++) {
        for (int j = 0; j < game.getY(); j++) {
            if(i == getPosition()[0] && j == getPosition()[1]){
                m.lock();
                std::sort(newField[i][j].begin(), newField[i][j].end(), std::greater<>());
                addPoints(newField[i][j][getPosition()[2]]);
                std::cout << "Descending Bot" << std::endl;
                std::cout << "You get " << newField[i][j][getPosition()[2]] << " points" << std::endl;
                std::cout << "Your total points are now " << getPoints() << std::endl;
                newField[i][j][getPosition()[2]] = 0;
                game.setField(newField);
                m.unlock();
            }
        }
    }
};