#pragma once
#include "cocos2d.h"
#include "GameLayer.h"
#include "Background.h"
#include "GameManager.h"
#include "GameEnd.h"

class GameRunning : public cocos2d::Scene
{
public:
    CREATE_FUNC(GameRunning);

    virtual bool init();

    void gameOver();
    void gameStart();

private:
    virtual void update(float delta);

    GameLayer* _gameLayer;
    Background* _background;
    GameEnd* _gameEnd;

    GameManager* _gameManager;
};

