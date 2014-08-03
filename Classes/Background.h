#pragma once
#include "cocos2d.h"

class Background : public cocos2d::Layer
{
public:
    virtual bool init();

    CREATE_FUNC(Background);

private:

    static std::string picturePath;

    cocos2d::Sprite* _backgroundPicture;
};

