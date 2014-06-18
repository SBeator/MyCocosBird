#pragma once
#include "cocos2d.h"

USING_NS_CC;

class Background : public Layer
{
public:
	virtual bool init();

	CREATE_FUNC(Background);

private:

	static std::string picturePath;

	Sprite* _backgroundPicture;
};

