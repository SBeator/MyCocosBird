#include "GameManager.h"
#include <cstdlib>
#include <ctime>
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

float GameManager::getRandomNumber(float maxNumber, float minNumber)
{
    return ((float)rand()) * (maxNumber - minNumber) / (float)RAND_MAX + minNumber;
}

bool GameManager::init()
{
    _director = Director::getInstance();

    srand(time(0));

    // TODO: no magic number
    _gamePlaceSize = Size(200, 200); 

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    _gameCenter = Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
     
    return true;
}  

Size GameManager::getGamePlaceSize() const
{
    return _gamePlaceSize;
}

Point GameManager::getGameCenter() const
{
    return _gameCenter;
}
