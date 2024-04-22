#include "DigBot.h"
#include "Game.h"

DigBot::DigBot(){
    setBotType(digging);
};

DigBot::~DigBot() = default;

void DigBot::act(Game& game, std::mutex& m) {
    vector<vector<vector<int>>> newField = game.getField();

    // print array before action
    /*
    for (int i = 0; i < game.getX(); i++) {
        for (int j = 0; j < game.getX(); j++) {
            if(i == getPosition()[0] && j == getPosition()[1]){
                for (int k = 1; k < game.getZ(); k++) {
                    std::cout << newField[i][j][k];
                }
            }
        }
    }
    std::cout << "" << std::endl;
    */

    m.lock();
    for (int i = 0; i < game.getX(); i++) {
        for (int j = 0; j < game.getX(); j++) {
            if(i == getPosition()[0] && j == getPosition()[1]){
                for (int k = 1; k < 4; k++) {

                    addPoints(newField[i][j][getPosition()[2]]);
                    std::cout << "Dig Bot" << std::endl;
                    std::cout << "position x: " << getPosition()[0] << " y: " << getPosition()[1] << " z: " << getPosition()[2] << std::endl;
                    std::cout << "Digging " << k << std::endl;
                    std::cout << "You get " << newField[i][j][getPosition()[2]] << " points" << std::endl;
                    std::cout << "Your total points are now " << getPoints() << std::endl;
                    newField[i][j][getPosition()[2]] = 0;
                    game.setField(newField);
                    goOneZDown();
                }
            }
        }
    }
    m.unlock();

    std::cout << "\n" << std::endl;

    // print array and points after action
    /*
    for (int i = 0; i < game.getX(); i++) {
        for (int j = 0; j < game.getX(); j++) {
            if(i == getPosition()[0] && j == getPosition()[1]){
                for (int k = 1; k < game.getZ(); k++) {
                    std::cout << newField[i][j][k];
                }
            }
        }
    }
    std::cout << "" << std::endl;

    std::cout << "Points:" << getPoints() << std::endl;
    */

};
