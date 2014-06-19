#pragma once
#include "cocos2d.h"
#include "Bird.h"

class GameLayer : public cocos2d::Layer
{
public:
	virtual bool init();

	CREATE_FUNC(GameLayer);

private:
    Bird* _bird;
};

