#include "Bird.h"

USING_NS_CC;
using namespace std;

#define FLY_FRAMES_NUMBER 3

string Bird::_flyFramePaths[FLY_FRAMES_NUMBER] = {
    "1.png",
    "2.png",
    "3.png"
};

int Bird::_width = 135;
int Bird::_height = 100;

bool Bird::init()
{
    Rect birdRect(0, 0, _width, _height);

    this->initWithFile(_flyFramePaths[0], birdRect);

    Vector<SpriteFrame*> frames;

    for (size_t i = 0; i < FLY_FRAMES_NUMBER; i++)
    {
        frames.pushBack(SpriteFrame::create(_flyFramePaths[i], birdRect));
    }

    _birdFlying = Animate::create(Animation::createWithSpriteFrames(frames, 0.3f));

    this->runAction(RepeatForever::create(_birdFlying));

    return true;
}


