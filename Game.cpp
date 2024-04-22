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

void Game::playSortBotAscending1(std::mutex& m){
    while(!checkIfFinished()) {
        sortBotAscending1.moveComputer(*this, m);
        sortBotAscending1.act(*this, m);
    }
}

void Game::playSortBotAscending2(std::mutex& m){
    while(!checkIfFinished()) {
        sortBotAscending2.moveComputer(*this, m);
        sortBotAscending2.act(*this, m);
    }
}

void Game::playSortBotDescending(std::mutex& m){
    while(!checkIfFinished()) {
        sortBotDescending.moveComputer(*this, m);
        sortBotDescending.act(*this, m);
    }
}

void Game::playDigBot1(std::mutex& m){
    while(!checkIfFinished()) {
        digBot1.moveComputer(*this, m);
        digBot1.act(*this, m);
    }
}

void Game::playDigBot2(std::mutex& m){
    while(!checkIfFinished()) {
        digBot2.moveComputer(*this, m);
        digBot2.act(*this, m);
    }
}

void Game::playGame(){
    std::mutex m;

    std::cout << "Welcome to Deep Miner!" << std::endl;

    threads[0] = std::thread([this, &m] { playSortBotAscending1(m); });
    threads[1] = std::thread([this, &m] { playSortBotAscending2(m); });
    threads[2] = std::thread([this, &m] { playSortBotDescending(m); });
    threads[3] = std::thread([this, &m] { playDigBot1(m); });
    threads[4] = std::thread([this, &m] { playDigBot2(m); });

    for (std::thread& thread : threads) {
        thread.join();
    }

    showWinner();
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

void Game::showWinner(){
    Bot* winner = bots[0];
    int winnerInt = 0;
    int counter = 0;


    for (Bot* singleBot : bots){
        counter++;
        if(singleBot->getPoints() > winner->getPoints()){
            winner = singleBot;
            winnerInt = counter;
        }
    }

    std::cout << "Who has how many points?" << std::endl;
    std::cout << "How many points where there in total? " << pointsTotal_ << std::endl;
    std::cout << "The Sort Bot Ascending 1 has " << sortBotAscending1.getPoints() << " points!" << std::endl;
    std::cout << "The Sort Bot Ascending 2 has " << sortBotAscending2.getPoints() << " points!" << std::endl;
    std::cout << "The Dig Deep Bot 1 has " << digBot1.getPoints() << " points!" << std::endl;
    std::cout << "The Dig Deep Bot 2 has " << digBot2.getPoints() << " points!" << std::endl;
    std::cout << "The Sort Descending has " << sortBotDescending.getPoints() << " points!" << std::endl;
    std::cout << "So the winner is: " << botNames[winnerInt - 1] << std::endl;
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

