#pragma once
#include "cocos2d.h"

class Bird : public cocos2d::Sprite
{
public:

    virtual bool init();
    CREATE_FUNC(Bird);

    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

private:

    virtual void update(float delta);
    float _velocityX;
    float _velocityY;
    float _deltaVelocityX;
    float _deltaVelocityY;

    cocos2d::Action* _flying;

    static float s_gravity;
    static float s_rotateFactor;
    static float s_riseVelocity;
    static float s_width;
    static float s_height;

    static std::string s_flyFramePaths[];
};

