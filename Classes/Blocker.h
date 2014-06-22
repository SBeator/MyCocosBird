#pragma once
#include "cocos2d.h"

class Blocker : public cocos2d::Sprite
{
public:

    virtual bool init();
    CREATE_FUNC(Blocker);

private:

    virtual void update(float delta);
    float _velocity;
    float _positionY;

    cocos2d::Sprite* _upBlocker;
    cocos2d::Sprite* _downBlocker;

    static float s_width;
    static float s_deltaHeight;

    static std::string s_imagePath;
    static cocos2d::Texture2D* s_image;
};

