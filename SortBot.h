#ifndef PROJECT_SORTBOT_H
#define PROJECT_SORTBOT_H
#include "Bot.h"

class Bot;

class SortBotAscending : public Bot {
public:
    SortBotAscending();
    virtual ~SortBotAscending() override;
    void act(Game& game) override;
};


#endif //PROJECT_SORTBOT_H
