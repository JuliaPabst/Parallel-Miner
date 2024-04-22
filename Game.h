#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H
#include <iostream>
#include <thread>
#include "Bot.h"
#include "SortBot.h"
#include "SortBotDescending.h"
#include "DigBot.h"

class Game {
public:
    Game();
    void fillField();
    void setField(std::vector<std::vector<std::vector<int>>> newField);
    void playGame(SortBotAscending& sortBotAscending, SortBotDescending& sortBotDescending, DigBot& digBot);
    void computerVSComputer(SortBotAscending& sortBotAscending, SortBotDescending& sortBotDescending, DigBot& digBot);
    bool checkIfFinished();
    void showWinner(SortBotAscending& sortBotAscending, SortBotDescending& sortBotDescending, DigBot& digBot);
    std::vector<std::vector<std::vector<int>>> getField();
    int getX();
    int getY();
    int getZ();
    std::vector<Bot*> getBots() const;

private:
    int x_;
    int y_;
    int z_;
    int numberOfBots_;
    std::vector<std::vector<std::vector<int>>> field_;
    int pointsTotal_;
    std::vector<Bot*> bots;
    DigBot digBot1;
    DigBot digBot2;
    SortBotAscending sortBotAscending1;
    SortBotAscending sortBotAscending2;
    SortBotDescending sortBotDescending;
    std::vector<std::thread> threads;
};


#endif //PROJECT_GAME_H
