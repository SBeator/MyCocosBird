#include "GameLayer.h"

USING_NS_CC;

bool GameLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }

    _gameManager = GameManager::getInstance();

    Point centerPoint = _gameManager->getGameCenter();

    _bird = Bird::create();
    _bird->setDefaultPosition();
    _bird->rise();

    this->addChild(_bird, 1);

    _blockers = Blockers::create();
    this->addChild(_blockers, 0);

    // Register Touch Event
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}

void GameLayer::stop()
{
    _bird->hitted();
    _blockers->stop();
}

bool GameLayer::checkIfBirdHitBlockerOrGround()
{
    return _blockers->hitBird(_bird) || _bird->hitGround();
}

bool GameLayer::onTouchBegan(Touch* touch, Event* event)
{
    _bird->onTouchBegan(touch, event);

    return true;
}






