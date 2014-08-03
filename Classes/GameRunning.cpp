#include "GameRunning.h"

USING_NS_CC;

bool GameRunning::init()
{
    if (!Scene::init())
    {
        return false;
    }

    _gameManager = GameManager::getInstance();

    _gameLayer = GameLayer::create();
    _background = Background::create();
    _gameEnd = GameEnd::create();
    _gameEnd->setVisible(false);

    this->addChild(_background, 0);
    this->addChild(_gameLayer, 1);
    this->addChild(_gameEnd, 2);

    _gameManager->resizeScene(this);

    this->scheduleUpdate();

    _running = true;

    return true;
}

void GameRunning::gameStart()
{
    _gameEnd->setVisible(false);

    _gameLayer->resume();
    _running = true;
}

void GameRunning::gameOver()
{
    _running = false;
    _gameEnd->setVisible(true);

    _gameLayer->stop();
}   

void GameRunning::update(float delta)
{
    if (_running)
    {
        if (_gameLayer->checkIfBirdHitBlockerOrGround())
        {
            this->gameOver();
        }
    }
}