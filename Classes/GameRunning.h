#pragma once
#include "cocos2d.h"
#include "GameLayer.h"
#include "Background.h"

class GameRunning : public cocos2d::Scene
{
public:
	CREATE_FUNC(GameRunning);

	virtual bool init();

private:
	GameLayer* _gameLayer;
	Background* _background;
};

