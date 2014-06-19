#include "GameRunning.h"

bool GameRunning::init()
{
	_gameLayer = GameLayer::create();
	_background = Background::create();

    this->addChild(_background, 0);
    this->addChild(_gameLayer, 1);

	return true;
}
