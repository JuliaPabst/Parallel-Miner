#ifndef PROJECT_SORTBOTDESCENDING_H
#define PROJECT_SORTBOTDESCENDING_H
#include "Bot.h"

class Bot;

class SortBotDescending : public Bot {
public:
    SortBotDescending();
    virtual ~SortBotDescending() override;
    void act(Game& game) override;
};


#endif //PROJECT_SORTBOTDESCENDING_H
