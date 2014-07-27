#include "GameLayer.h"

USING_NS_CC;

bool GameLayer::init()
{
    _gameManager = GameManager::getInstance();

    Point centerPoint = _gameManager->getGameCenter();

    _bird = Bird::create();
    _bird->setPosition(centerPoint);

    this->addChild(_bird);

    _blockers = Blockers::create();
    this->addChild(_blockers);

    // Register Touch Event
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);

    listener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}

bool GameLayer::checkIfBirdHitBlockerOrGround()
{
    return _blockers->hitBird(_bird);
}

bool GameLayer::onTouchBegan(Touch* touch, Event* event)
{
    _bird->onTouchBegan(touch, event);

    return true;
}






