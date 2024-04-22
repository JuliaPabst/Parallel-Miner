#include "Game.h"
#include <random>
#include <cstdlib> // srand()
#include <ctime>

Game::Game() : x_(5), y_(5), z_(10), numberOfBots_(3), pointsTotal_(0), field_(x_, vector<vector<int>>(y_, vector<int>(z_, 0))){
    fillField();

    bots.reserve(5);
    bots.push_back(&digBot1);
    bots.push_back(&digBot2);
    bots.push_back(&sortBotAscending1);
    bots.push_back(&sortBotAscending2);
    bots.push_back(&sortBotDescending);

    threads.reserve(5);
    threads.emplace_back();
    threads.emplace_back(func2);
    threads.emplace_back(func3);
    threads.emplace_back(func4);
    threads.emplace_back(func5);
}

void Game::fillField() {
    for(int i = 0; i < x_; i++){
        for(int j = 0; j < y_; j++){
            for(int k = 0; k < z_; k++){
                int randomNumber = (rand() % 9) + 1;
                field_[i][j][k] = randomNumber;
                pointsTotal_ += randomNumber;
            }
        }
    }
}

void Game::playGame(SortBotAscending& sortBotAscending, SortBotDescending& sortBotDescending, DigBot& digBot){
    std::cout << "Welcome to Deep Miner!" << std::endl;

    computerVSComputer(sortBotAscending, sortBotDescending, digBot);
};

bool Game::checkIfFinished() {
    for(int i = 0; i < x_; i++){
        for(int j = 0; j < y_; j++){
            if(field_[i][j][0] != 0){
                return false;
            }
        }
    }
    return true;
}

void Game::computerVSComputer(SortBotAscending& sortBotAscending, SortBotDescending& sortBotDescending, DigBot& digBot){
    while(!checkIfFinished()){
        sortBotAscending.moveComputer(*this);
        sortBotAscending.act(*this);
        digBot.moveComputer(*this);
        digBot.act(*this);
        sortBotDescending.moveComputer(*this);
        sortBotDescending.act(*this);
    }

    showWinner(sortBotAscending, sortBotDescending, digBot);
}

void Game::showWinner(SortBotAscending& sortBotAscending, SortBotDescending& sortBotDescending, DigBot& digBot){
    Bot* bots[] = {&sortBotAscending, &sortBotDescending, &digBot};
    Bot* winner = &sortBotAscending;

    for (int i = 0; i < numberOfBots_; i++){
        if(bots[i]->getPoints() > winner->getPoints()){
            winner = bots[i];
        }
    }

    std::cout << "Who has how many points?" << std::endl;
    std::cout << "How many points where there in total? " << pointsTotal_ << std::endl;
    std::cout << "The Sort Bot Ascending has " << sortBotAscending.getPoints() << " points!" << std::endl;
    std::cout << "The Sort Descending has " << sortBotDescending.getPoints() << " points!" << std::endl;
    std::cout << "The Dig Deep Bot has " << digBot.getPoints() << " points!" << std::endl;
    std::cout << "So the winner is: " << winner->getBotTypesStrings()[winner->getBotType()] << std::endl;
}

vector<vector<vector<int>>> Game::getField(){
    return field_;
};

int Game::getX(){
    return x_;
}

int Game::getY(){
    return y_;
}

int Game::getZ(){
    return z_;
}

void Game::setField(vector<vector<vector<int>>> newField){
    field_ = newField;
}

std::vector<Bot*> Game::getBots() const{
    return bots;
}

