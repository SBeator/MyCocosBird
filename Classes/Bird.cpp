#include "Bird.h"
#include "GameManager.h"

USING_NS_CC;
using namespace std;

#define FLY_FRAMES_NUMBER 3

string Bird::s_flyFramePaths[FLY_FRAMES_NUMBER] = {
    "1.png",
    "2.png",
    "3.png"
};

int frameWidth = 135;
int frameHeight = 100;

float scale = 0.3;
float frameDelay = 0.2f;

float Bird::s_width = frameWidth * scale;
float Bird::s_height = frameHeight * scale;

float Bird::s_rotateFactor = -10;
float Bird::s_riseVelocity = 5;

bool Bird::init()
{
    if (!Sprite::init())
    {
        return false;
    }

    _gravity = -10;
    _velocityX = 0;
    _velocityY = 0;
    _deltaVelocityX = 0;
    _deltaVelocityY = _gravity;


    Rect frameRect(0, 0, frameWidth, frameHeight);
    Rect birdRect(0, 0, s_width, s_height);

    Size originSize((float)frameWidth / scale, (float)frameHeight / scale);

    this->initWithFile(s_flyFramePaths[0]);
    this->setScale(scale);
    this->setAnchorPoint(Point(0.4, 0.5));
   
    Vector<SpriteFrame*> frames;

    for (size_t i = 0; i < FLY_FRAMES_NUMBER; i++)
    {
        auto frame = SpriteFrame::create(s_flyFramePaths[i], frameRect, false, Point::ZERO, originSize);
        frames.pushBack(frame);
    }

    _flying = RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(frames, frameDelay)));


    this->runAction(_flying);

    this->scheduleUpdate();

    _pause = false;

    return true;
}

void Bird::update(float delta)
{
    if (!_pause)
    {
        Point point = this->getPosition();

        _velocityX += _deltaVelocityX * delta;
        _velocityY += _deltaVelocityY * delta;

        point += Point(_velocityX, _velocityY);

        float rotate = _velocityY * s_rotateFactor;

        rotate = rotate > 90 ?
            90 :
            rotate < -90 ?
            -90 :
            rotate;

        this->setPosition(point);
        this->setRotation(rotate);
    }
}

bool Bird::onTouchBegan(Touch* touch, Event* event)
{
    this->rise();
    return true;
}

void Bird::setDefaultPosition()
{
    Point center = GameManager::getInstance()->getGameCenter();
    center.x -= s_width;
    this->setPosition(center);
}

void Bird::rise()
{
    _velocityY = s_riseVelocity;
}

void Bird::hitted()
{
    _deltaVelocityY *= 2;
}

Rect Bird::getBoundingBox() const
{
    Point offsetPoint(this->getAnchorPoint());
    const float scaleX = this->getScaleX();
    const float scaleY = this->getScaleY();

    Rect rect(Sprite::getBoundingBox());

    rect.origin.x += offsetPoint.x * rect.size.width * (1 - scaleX);
    rect.origin.y += offsetPoint.y * rect.size.height * (1 - scaleY);

    rect.size.width *= scaleX;
    rect.size.height *= scaleY;

    return rect;
}

void Bird::setGravity(float gravity)
{
    _gravity = 0;
    _deltaVelocityY = 0;
}

bool Bird::hitGround()
{
    auto position = this->getPosition();
    auto size = GameManager::getInstance()->getGamePlaceSize();

    bool result;
    if (position.y <  - s_height)
    {
        result = true;
    }
    else if (position.y > size.height * 2)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}