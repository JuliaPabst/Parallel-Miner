#include "SortBot.h"
#include <iostream>
#include "Bot.h"
#include "Game.h"


SortBotAscending::SortBotAscending(){
    setBotType(sortingAscending);
};

SortBotAscending::~SortBotAscending() = default;

void SortBotAscending::act(Game& game, std::mutex& m) {
    vector<vector<vector<int>>> newField = game.getField();

    for (int i = 0; i < game.getX(); i++) {
        for (int j = 0; j < game.getY(); j++) {
            if(i == getPosition()[0] && j == getPosition()[1]){
                m.lock();
                std::sort(newField[i][j].begin(), newField[i][j].end());
                addPoints(newField[i][j][getPosition()[2]]);
                std::cout << "Ascending Bot" << std::endl;
                std::cout << "You get " << newField[i][j][getPosition()[2]] << " points" << std::endl;
                std::cout << "Your total points are now " << getPoints() << std::endl;
                newField[i][j][getPosition()[2]] = 0;
                game.setField(newField);
                m.unlock();
            }
        }
    }

    std::cout << "\n" << std::endl;
};