#include "GameRunning.h"

bool GameRunning::init()
{
	_gameLayer = GameLayer::create();
	_background = Background::create();

	this->addChild(_gameLayer, 1);
	this->addChild(_background, 1);

	return true;
}
