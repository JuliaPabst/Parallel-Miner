#include "Bot.h"
#include <iostream>
#include <cstdlib> // srand()
#include <ctime>
#include "Game.h"

Bot::Bot() : botType_(none), points_(0) {
    place();
}

Bot::~Bot() = default;

void Bot::place() {
    int x = rand() % 5;
    int y = rand() % 5;

    position_.resize(3);
    position_[0] = x;
    position_[1] = y;
    position_[2] = 9;

    position_.resize(3);
};

void Bot::moveComputer(Game& game){
    int x = rand() % 4;


    if(x == 0){
        if (position_[1] == 0){
            position_[1] = 4;
        } else {
            position_[1]--;
        }
    } else if (x == 1){
        if (position_[0] == 0){
            position_[0] = 4;
        } else {
            position_[0]--;
        }
    } else if (x == 2){
        if (position_[1] == 4){
            position_[1] = 0;
        } else {
            position_[1]++;
        }
    } else if (x == 3){
        if (position_[0] == 4){
            position_[0] = 0;
        } else {
            position_[0]++;
        }
    }
}

int Bot::findNewZ(Game& game){
    int newZ = game.getZ();
    while(game.getField()[position_[0]][position_[1]][newZ] == 0){
        newZ--;
    }

    return newZ;
}

void Bot::addPoints(int points){
    points_ += points;
}

void Bot::goOneZDown(){
    if(position_[2] > 0){
        position_[2]--;
    }
};

vector <int> Bot::getPosition(){
    return position_;
}

int Bot::getPoints(){
  return points_;
};

BotType Bot::getBotType(){
    return botType_;
}

string* Bot::getBotTypesStrings(){
    return botTypesStrings_;
}

void Bot::setBotType(BotType botType) {
    botType_ = botType;
};

void Bot::setPosition(vector <int> position){
    position_ = position;
};

