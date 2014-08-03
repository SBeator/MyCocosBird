#include "GameManager.h"
#include <cstdlib>
#include <ctime>
#include "GameRunning.h"
#include "GameBeginning.h"

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

void GameManager::beginGame()
{
    _gameBeginning = GameBeginning::create();

    _director->pushScene(_gameBeginning);
}

void GameManager::startGame()
{
    _gameRunning = GameRunning::create();

    _director->pushScene(_gameRunning);
}

void GameManager::resizeScene(Scene* scene)
{
    auto gameCenter = this->getGameCenter();
    auto scale = this->getScreenScale();
    scene->setScale(this->getScreenScale());
}

float GameManager::getRandomNumber(float maxNumber, float minNumber)
{
    return ((float)rand()) * (maxNumber - minNumber) / (float)RAND_MAX + minNumber;
}

bool GameManager::init()
{
    _director = Director::getInstance();

    srand(time(0));


    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    _gameCenter = Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);

    // TODO: no magic number
    _gamePlaceSize = Size(400, 400);

    float scaleY = visibleSize.height / _gamePlaceSize.height;
    float scaleX = visibleSize.width / _gamePlaceSize.width;

    _screenScale = scaleY > scaleX ? scaleY : scaleX;
    _gamePlaceSize = visibleSize / _screenScale;
     
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

float GameManager::getScreenScale() const
{
    return _screenScale;
}
