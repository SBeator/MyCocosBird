#include "Bird.h"

USING_NS_CC;
using namespace std;

#define FLY_FRAMES_NUMBER 3

string Bird::_flyFramePaths[FLY_FRAMES_NUMBER] = {
    "1.png",
    "2.png",
    "3.png"
};

int frameWidth = 135;
int frameHeight = 100;

float scale = 0.3;

int Bird::_width = frameWidth * scale;
int Bird::_height = frameHeight * scale;

float Bird::_gravity = -10;
float Bird::_rotateFactor = -10;
float Bird::_riseVelocity = 5;

bool Bird::init()
{
    _velocityX = 0;
    _velocityY = 0;
    _deltaVelocityX = 0;
    _deltaVelocityY = _gravity;


    Rect frameRect(0, 0, frameWidth, frameHeight);
    Rect birdRect(0, 0, _width, _height);

    Size originSize((float)frameWidth / scale, (float)frameHeight / scale);

    this->initWithFile(_flyFramePaths[0]);
    this->setScale(scale);
   
    Vector<SpriteFrame*> frames;

    for (size_t i = 0; i < FLY_FRAMES_NUMBER; i++)
    {
        auto frame = SpriteFrame::create(_flyFramePaths[i], frameRect, false, Point::ZERO, originSize);
        frames.pushBack(frame);
    }

    _flying = RepeatForever::create(Animate::create(Animation::createWithSpriteFrames(frames, 0.3f)));


    this->runAction(_flying);

    this->scheduleUpdate();


    return true;
}

void Bird::update(float delta)
{
    Point point = this->getPosition();

    _velocityX += _deltaVelocityX * delta;
    _velocityY += _deltaVelocityY * delta;

    point += Point(_velocityX, _velocityY);

    float rotate = _velocityY * _rotateFactor;

    rotate = rotate > 90 ?
                90 : 
                rotate < -90 ?
                    -90 : 
                    rotate;

    this->setPosition(point);
    this->setRotation(rotate);
}

bool Bird::onTouchBegan(Touch* touch, Event* event)
{
    _velocityY = _riseVelocity;

    return true;
}

