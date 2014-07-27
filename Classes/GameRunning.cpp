#include "GameRunning.h"

USING_NS_CC;

bool GameRunning::init()
{
    _gameLayer = GameLayer::create();
	_background = Background::create();

    this->addChild(_background, 0);
    this->addChild(_gameLayer, 1);

    this->scheduleUpdate();

	return true;
}

void GameRunning::update(float delta)
{
    if (_gameLayer->checkIfBirdHitBlockerOrGround())
    {
        Director::getInstance()->stopAnimation();
    }
}