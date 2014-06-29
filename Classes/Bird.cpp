#include "Bird.h"

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

float Bird::s_gravity = -10;
float Bird::s_rotateFactor = -10;
float Bird::s_riseVelocity = 5;

bool Bird::init()
{
    _velocityX = 0;
    _velocityY = 0;
    _deltaVelocityX = 0;
    _deltaVelocityY = s_gravity;


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


    return true;
}

void Bird::update(float delta)
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

bool Bird::onTouchBegan(Touch* touch, Event* event)
{
    _velocityY = s_riseVelocity;

    return true;
}

