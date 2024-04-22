#include "Game.h"
#include <random>
#include <cstdlib> // srand()
#include <ctime>

Game::Game() : x_(5), y_(5), z_(10), numberOfBots_(3), pointsTotal_(0), field_(x_, vector<vector<int>>(y_, vector<int>(z_, 0))){
    fillField();
}

void Game::clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
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
    int mode = 0;
    int chosenBot = 0;
    std::cout << "Welcome to Deep Miner!" << std::endl;
    std::cout << "In which mode would you like to play? Player vs. Computer (1) or Computer vs. Computer (2)" << std::endl;
    std::cin >> mode;

    if (mode == 1){
        std::cout << "You chose the mode: Player vs. Computer" << std::endl;
        std::cout << "Which bot would you like to play? Sort ascending (1), sort descending (2), dig deep (3)" << std::endl;
        std::cin >> chosenBot;
        playerVSComputer(chosenBot, sortBotAscending, sortBotDescending, digBot);
    } else if (mode == 2){
        computerVSComputer(sortBotAscending, sortBotDescending, digBot);
    }
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

void Game::playerVSComputer(int chosenBot, SortBotAscending& sortBotAscending, SortBotDescending& sortBotDescending, DigBot& digBot){
    if(chosenBot == 1){
        while(sortBotAscending.movePlayer(*this) != 'x' && !checkIfFinished()){
            sortBotAscending.act(*this);
            digBot.moveComputer(*this);
            digBot.act(*this);
            sortBotDescending.moveComputer(*this);
            sortBotDescending.act(*this);
        }
    } else if(chosenBot == 2){
        while(sortBotDescending.movePlayer(*this) != 'x' && !checkIfFinished()){
            sortBotDescending.act(*this);
            sortBotAscending.moveComputer(*this);
            sortBotAscending.act(*this);
            digBot.moveComputer(*this);
            digBot.act(*this);
        }
    } else if(chosenBot == 3){
        while(digBot.movePlayer(*this) != 'x' && !checkIfFinished()){
            digBot.act(*this);
            sortBotAscending.moveComputer(*this);
            sortBotAscending.act(*this);
            sortBotDescending.moveComputer(*this);
            sortBotDescending.act(*this);
        }
    }

    showWinner(sortBotAscending, sortBotDescending, digBot);
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