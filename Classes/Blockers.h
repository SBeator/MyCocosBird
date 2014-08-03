#pragma once
#include "cocos2d.h"
#include "Blocker.h"
#include "GameManager.h"
#include "Bird.h"

class Blockers : public cocos2d::Layer
{
public:
    virtual bool init();
    CREATE_FUNC(Blockers);

    void addBlocker(Blocker* blocker);
    void addRandomBlocker();

    bool hitBird(Bird* bird);

    void stop();

private:
    virtual void update(float delta);
    void removeBlockerIfOut();

    bool _pause;

    cocos2d::Vector<Blocker*> _blockers;
    float _blockerCreateTime;

    GameManager* _gameManager;
};

