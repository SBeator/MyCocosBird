#pragma once
#include "cocos2d.h"

class GameManager
{
public:
    static GameManager* getInstance();
    
    void beginGame();
    void startGame();

    void resizeScene(cocos2d::Scene* scene);

    float getRandomNumber(float maxNumber = 1, float minNumber = 0);

    CC_PROPERTY_READONLY(cocos2d::Size, _gamePlaceSize, GamePlaceSize)
    CC_PROPERTY_READONLY(cocos2d::Point, _gameCenter, GameCenter)
    CC_PROPERTY_READONLY(float, _screenScale, ScreenScale)
private:
    bool init();

    cocos2d::Scene* _gameRunning;
    cocos2d::Scene* _gameBeginning;

    static GameManager* _gameManager;
    cocos2d::Director* _director;
};

