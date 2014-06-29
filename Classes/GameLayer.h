#pragma once
#include "cocos2d.h"
#include "Bird.h"
#include "Blocker.h"
#include "GameManager.h"

class GameLayer : public cocos2d::Layer
{
public:
	virtual bool init();

	CREATE_FUNC(GameLayer);

    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

private:
    virtual void update(float delta);
    cocos2d::Point getCenterPoint();

    void addBlocker(Blocker* blocker); 
    void addRandomBlocker();
    
    GameManager* _gameManager;
    Bird* _bird;

    // TODO: extend this to a new class
    cocos2d::Vector<Blocker*>* _Blockers;
    float _blockerCreateTime;

};

