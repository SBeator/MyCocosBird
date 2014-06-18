#include "Background.h"

USING_NS_CC;
using namespace std;

string Background::picturePath = "Background.png";

bool Background::init()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Point origin = Director::getInstance()->getVisibleOrigin();

	auto picture = Sprite::create(picturePath);

	picture->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(picture, 0);

	_backgroundPicture = picture;

	return true;
}


