#ifndef PROJECT_GAME_H
#define PROJECT_GAME_H
#include <iostream>
#include "Bot.h"
#include "SortBot.h"
#include "SortBotDescending.h"
#include "DigBot.h"

class Game {
public:
    Game();
    void clearConsole();
    void fillField();
    void setField(std::vector<std::vector<std::vector<int>>> newField);
    void playGame(SortBotAscending& sortBotAscending, SortBotDescending& sortBotDescending, DigBot& digBot);
    void playerVSComputer(int chosenBot, SortBotAscending& sortBotAscending, SortBotDescending& sortBotDescending, DigBot& digBot);
    void computerVSComputer(SortBotAscending& sortBotAscending, SortBotDescending& sortBotDescending, DigBot& digBot);
    bool checkIfFinished();
    void showWinner(SortBotAscending& sortBotAscending, SortBotDescending& sortBotDescending, DigBot& digBot);
    std::vector<std::vector<std::vector<int>>> getField();
    int getX();
    int getY();
    int getZ();


private:
    int x_;
    int y_;
    int z_;
    int numberOfBots_;
    std::vector<std::vector<std::vector<int>>> field_;
    int pointsTotal_;
};


#endif //PROJECT_GAME_H
