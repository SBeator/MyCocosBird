#pragma once
#include "cocos2d.h"

class GameManager
{
public:
	static GameManager* getInstance();
    
    void startGame();

    void stopGame();

    float getRandomNumber(float maxNumber = 1, float minNumber = 0);

    CC_PROPERTY_READONLY(cocos2d::Size, _gamePlaceSize, GamePlaceSize)
    CC_PROPERTY_READONLY(cocos2d::Point, _gameCenter, GameCenter)
private:
    bool init();

    static GameManager* _gameManager;
    cocos2d::Director* _director;
};

