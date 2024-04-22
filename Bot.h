#ifndef PROJECT_BOT_H
#define PROJECT_BOT_H
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>

using namespace std;

typedef enum BotType{
    none, sortingAscending, sortingDescending, digging
} BotType;

class Game;

class Bot {
public:
    Bot();
    virtual ~Bot();
    virtual void act(Game& game) = 0;
    void place();
    void moveComputer(Game& game, std::mutex m);
    int findNewZ(Game& game);
    void addPoints(int points);
    void goOneZDown();
    vector <int> getPosition();
    int getPoints();
    BotType getBotType();
    string* getBotTypesStrings();
    void setBotType(BotType botType);
    void setPosition(vector <int> position);
    bool checkIfFieldIsTaken(std::vector <int> position, Game game);

private:
    BotType botType_;
    std::vector <int> position_;
    int points_;
    std::string botTypesStrings_[4] = {"None", "Sort Bot Ascending", "Sort Bot Descending", "Dig Deep Bot"};
};


#endif //PROJECT_BOT_H
