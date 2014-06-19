#include "GameLayer.h"

USING_NS_CC;


bool GameLayer::init()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();


    _bird = Bird::create();
    _bird->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    this->addChild(_bird, 1);

    return true;
}


