#include "GameBeginning.h"

USING_NS_CC;

bool GameBeginning::init()
{
    if (!Scene::init())
    {
        return false;
    }

    _gameManager = GameManager::getInstance();

    _welcomeLayer = WelcomeLayer::create();

    this->addChild(_welcomeLayer, 0);

    _gameManager->resizeScene(this);

    this->scheduleUpdate();

    return true;
}