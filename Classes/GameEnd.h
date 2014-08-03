#pragma once
#include "cocos2d.h"
#include "Blocker.h"
#include "GameManager.h"
#include "Bird.h"

class GameEnd : public cocos2d::Layer
{
public:
    virtual bool init();
    CREATE_FUNC(GameEnd);

private:
    void continueGame();

    cocos2d::Sprite* _gameOverLabel;

    static std::string s_gameOverLabelPath;
    static std::string s_continuePath;
    static std::string s_continuePressedPath;
};

