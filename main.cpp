#include <iostream>
#include "Bot.h"
#include "SortBot.h"
#include "SortBotDescending.h"
#include "DigBot.h"
#include "Game.h"
#include "Test.h"
#include <cstdlib> // srand()
#include <ctime>

int main() {
    srand(time(NULL));
    Game game;
    SortBotAscending sortBotAscending;
    SortBotDescending sortBotDescending;
    DigBot digBot;

    game.playGame(sortBotAscending, sortBotDescending, digBot);


    /*Test test;
    test.runTests();
     */
    return 0;
}