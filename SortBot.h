#ifndef PROJECT_SORTBOT_H
#define PROJECT_SORTBOT_H
#include "Bot.h"

class Game;

class SortBotAscending : public Bot {
public:
    SortBotAscending();
    virtual ~SortBotAscending() override;
    void act(Game& game, std::mutex& m) override;
};


#endif //PROJECT_SORTBOT_H
