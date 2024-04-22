#ifndef PROJECT_DIGBOT_H
#define PROJECT_DIGBOT_H
#include "Bot.h"


class DigBot : public Bot {
public:
    DigBot();
    virtual ~DigBot();
    void act(Game& game) override;
};


#endif //PROJECT_DIGBOT_H
