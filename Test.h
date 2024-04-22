#include <cassert> // Für assert()
#include "Game.h"
#include "SortBot.h"
#include "SortBotDescending.h"
#include "DigBot.h"
#include <mutex>
#ifndef PROJECT_TEST_H
#define PROJECT_TEST_H


class Test {
public:
    void runTests();

private:
    void testInitialization();
    void testBotActions();
    void testPointCalculation();
};


#endif //PROJECT_TEST_H
