#pragma once
#include "cocos2d.h"
#include "Bird.h"

class Blocker : public cocos2d::Layer
{
public:

    virtual bool init();
    CREATE_FUNC(Blocker);

    CC_PROPERTY_READONLY(float, _width, Width)

    bool hitBird(Bird* bird);

private:

    virtual void update(float delta);
    float _velocity;

    cocos2d::Sprite* _upBlocker;
    cocos2d::Sprite* _downBlocker;

    static float s_deltaHeight;
    static float s_velocity;

    static std::string s_imagePath;
};

