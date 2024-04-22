#ifndef PROJECT_DIGBOT_H
#define PROJECT_DIGBOT_H
#include "Bot.h"

class Bot;

class DigBot : public Bot {
public:
    DigBot();
    virtual ~DigBot();
    void act(Game& game, std::mutex& m) override;
};


#endif //PROJECT_DIGBOT_H
