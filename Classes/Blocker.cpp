#include "Blocker.h"

USING_NS_CC;
using namespace std;


string Blocker::s_imagePath = "BlockerDown.png";

float Blocker::s_deltaHeight = 150;
float Blocker::s_velocity =-3;

bool Blocker::init()
{
    _velocity = s_velocity;

    _downBlocker = Sprite::create(s_imagePath);
    _upBlocker = Sprite::create(s_imagePath);

    _width = _downBlocker->getContentSize().width;

    _downBlocker->setAnchorPoint(Point(0.5, 1));
    _upBlocker->setAnchorPoint(Point(0.5, 1));

    _upBlocker->setRotation(180);

    _downBlocker->setPosition(Point(0, -s_deltaHeight / 2));
    _upBlocker->setPosition(Point(0, s_deltaHeight / 2));

    this->addChild(_upBlocker, 2);
    this->addChild(_downBlocker, 2);

    this->scheduleUpdate();

    return true;
}

void Blocker::update(float delta)
{
    auto position = this->getPosition();

    position.x += _velocity;

    this->setPosition(position);
}

float Blocker::getWidth() const
{
    return _width;
}
