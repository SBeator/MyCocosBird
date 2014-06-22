#pragma once
#include "cocos2d.h"

class GameManager
{
public:
	static GameManager* getInstance();
    
    void startGame();

private:
    bool init();

    static GameManager* _gameManager;
    cocos2d::Director* _director;
};

