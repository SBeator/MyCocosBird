#pragma once
#include "cocos2d.h"
#include "Blocker.h"
#include "GameManager.h"

class Blockers : public cocos2d::Layer
{
public:
    virtual bool init();
    CREATE_FUNC(Blockers);

    void addBlocker(Blocker* blocker);
    void addRandomBlocker();

private:
    virtual void update(float delta);

    cocos2d::Vector<Blocker*>* _Blockers;
    float _blockerCreateTime;

    GameManager* _gameManager;
};

