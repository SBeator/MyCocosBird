#include "GameManager.h"
#include "GameRunning.h"

USING_NS_CC;

GameManager* GameManager::_gameManager;

GameManager* GameManager::getInstance()
{
    if (!_gameManager)
    {
        _gameManager = new GameManager();
        _gameManager->init();
    }

    return _gameManager;
}

void GameManager::startGame()
{
    auto scene = GameRunning::create();

    _director->runWithScene(scene);
}

bool GameManager::init()
{
    _director = Director::getInstance();
     
    return true;
}   