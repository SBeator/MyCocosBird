#pragma once
#include "cocos2d.h"

class Bird : public cocos2d::Sprite
{
public:
    virtual bool init();

    CREATE_FUNC(Bird);

private:

    cocos2d::Animate* _birdFlying;

    static int _width;
    static int _height;
    static std::string _flyFramePaths[];
};

