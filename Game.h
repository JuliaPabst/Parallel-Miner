#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H
#include <iostream>
#include <thread>
#include <mutex>
#include "Bot.h"
#include "SortBot.h"
#include "SortBotDescending.h"
#include "DigBot.h"

class Game {
public:
    Game();
    void fillField();
    void setField(std::vector<std::vector<std::vector<int>>> newField);
    void playGame();
    bool checkIfFinished();
    void showWinner();
    std::vector<std::vector<std::vector<int>>> getField();
    int getX();
    int getY();
    int getZ();
    std::vector<Bot*> getBots() const;
    void playSortBotAscending1(std::mutex& m);
    void playSortBotAscending2(std::mutex& m);
    void playSortBotDescending(std::mutex& m);
    void playDigBot1(std::mutex& m);
    void playDigBot2(std::mutex& m);

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
    std::vector<std::string> botNames = {"Dig Deep Bot 1", "Dig Deep Bot 2", "Sort Bot Ascending 1", "Sort Bot Ascending 2", "Sort Bot Descending"};
    std::thread threads[5];
};


#endif //PROJECT_GAME_H
