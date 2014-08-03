#pragma once
#include "cocos2d.h"
#include "Bird.h"

class WelcomeLayer : public cocos2d::Layer
{
public:
    virtual bool init();

    CREATE_FUNC(WelcomeLayer);

private:

    static std::string picturePath;

    cocos2d::Sprite* _welcomeLayerPicture;
    Bird* _bird;

    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
};

