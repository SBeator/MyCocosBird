#include "WelcomeLayer.h"
#include "GameManager.h"

USING_NS_CC;
using namespace std;

string WelcomeLayer::picturePath = "WelcomePage.png";

bool WelcomeLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    auto picture = Sprite::create(picturePath);

    picture->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(picture, 0);

    Point centerPoint = GameManager::getInstance()->getGameCenter();
    auto bird = Bird::create();
    bird->setDefaultPosition();
    bird->setGravity(0);
    this->addChild(bird, 1);

    _welcomeLayerPicture = picture;
    _bird = bird;

    // Register Touch Event
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = CC_CALLBACK_2(WelcomeLayer::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}

bool WelcomeLayer::onTouchBegan(Touch* touch, Event* event)
{
    GameManager::getInstance()->startGame();

    return true;
}

