#include "GameLayer.h"

USING_NS_CC;


bool GameLayer::init()
{
    _gameManager = GameManager::getInstance();

    Point centerPoint = this->getCenterPoint();

    _bird = Bird::create();
    _bird->setPosition(centerPoint);

    this->addChild(_bird);

    _Blockers = new Vector<Blocker*>();

    this->addRandomBlocker();

    // Register Touch Event
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);

    listener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    _blockerCreateTime = 2;
    this->scheduleUpdate();

    return true;
}

bool GameLayer::onTouchBegan(Touch* touch, Event* event)
{
    _bird->onTouchBegan(touch, event);

    return true;
}

float updateTime = 0;
void GameLayer::update(float delta)
{
    updateTime += delta;

    if (updateTime > _blockerCreateTime)
    {
        this->addRandomBlocker();
        updateTime = 0;
    }
}

Point GameLayer::getCenterPoint()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    return Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);
}

void GameLayer::addRandomBlocker()
{
    auto point = this->getCenterPoint();

    auto size = _gameManager->getGamePlaceSize();
    auto offset = _gameManager->getRandomNumber(size.height, -size.height);

    auto blocker = Blocker::create();
    blocker->setPosition(point + Point(size.width , offset));

    this->addBlocker(blocker);
}

void GameLayer::addBlocker(Blocker* blocker)
{
    _Blockers->pushBack(blocker);
    this->addChild(blocker);
}


