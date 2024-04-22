#include "Test.h"

void Test::testBotActions() {
    Game game;
    SortBotAscending sortBotAscending;
    SortBotDescending sortBotDescending;
    DigBot digBot;

    // Test initial position of bot
    std::vector<int> initialPosition = sortBotAscending.getPosition();
    assert(initialPosition[0] >= 0 && initialPosition[0] < game.getX());
    assert(initialPosition[1] >= 0 && initialPosition[1] < game.getY());
    assert(initialPosition[2] == 9);

    // Test movement of bot
    /*
    sortBotAscending.moveComputer(game, m);
    std::vector<int> newPosition = sortBotAscending.getPosition();
    assert(newPosition != initialPosition);
     */

    // Test action of bot and change of points
    int initialPoints = sortBotAscending.getPoints();
    sortBotAscending.act(game);
    int newPoints = sortBotAscending.getPoints();
    assert(newPoints >= initialPoints);

    std::cout << "Bot action tests successful." << std::endl;
}

void Test::testInitialization() {
    Game game;
    assert(game.getX() == 5 && game.getY() == 5 && game.getZ() == 10); // example values
    std::cout << "Test of initialization successful." << std::endl;
}

void Test::testPointCalculation() {
    Game game;
    SortBotAscending sortBotAscending;
    SortBotDescending sortBotDescending;
    DigBot digBot;

   // create a known playing field
    std::vector<std::vector<std::vector<int>>> testField(5, std::vector<std::vector<int>>(5, std::vector<int>(10, 0)));
    // place known points
    testField[2][2][9] = 5;
    game.setField(testField);

    // put bot on 2,2,9
    sortBotAscending.setPosition({2, 2, 9});
    sortBotDescending.setPosition({2, 2, 9});
    digBot.setPosition({2, 2, 9});

    // action: bot collects points
    sortBotAscending.act(game);
    sortBotDescending.act(game);
    digBot.act(game);

    // check if bot collected the right points
    assert(sortBotAscending.getPoints() == 5);
    assert(sortBotDescending.getPoints() == 0);
    assert(digBot.getPoints() == 0);

    std::cout << "Point test successful." << std::endl;
}

void Test::runTests() {
    testInitialization();
    testBotActions();
    testPointCalculation();
    std::cout << "All Tests are running successfully." << std::endl;
}