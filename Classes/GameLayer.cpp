#include "GameLayer.h"

USING_NS_CC;


bool GameLayer::init()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();


    _bird = Bird::create();
    _bird->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    this->addChild(_bird);

    auto blocker = Blocker::create();
    blocker->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    this->addChild(blocker);

    // Register Touch Event
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);

    listener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}

bool GameLayer::onTouchBegan(Touch* touch, Event* event)
{
    _bird->onTouchBegan(touch, event);

    return true;
}


