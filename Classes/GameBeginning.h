#pragma once
#include "cocos2d.h"
#include "WelcomeLayer.h"
#include "GameManager.h"

class GameBeginning : public cocos2d::Scene
{
public:
    CREATE_FUNC(GameBeginning);

    virtual bool init();

private:
    WelcomeLayer* _welcomeLayer;

    GameManager* _gameManager;
};

