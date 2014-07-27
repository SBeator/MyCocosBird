#pragma once
#include "cocos2d.h"
#include "Bird.h"
#include "Blockers.h"
#include "GameManager.h"

class GameLayer : public cocos2d::Layer
{
public:
	virtual bool init();

	CREATE_FUNC(GameLayer);

    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

    bool checkIfBirdHitBlockerOrGround();

private:
    GameManager* _gameManager;
    Bird* _bird;
    Blockers* _blockers;
};

