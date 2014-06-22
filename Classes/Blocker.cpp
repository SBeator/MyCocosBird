#include "Blocker.h"

USING_NS_CC;
using namespace std;


string Blocker::s_imagePath = "BlockerDown.png";
Texture2D* Blocker::s_image = Director::getInstance()->getTextureCache()->addImage(s_imagePath);

float Blocker::s_width = 200;
float Blocker::s_deltaHeight = 200;


bool Blocker::init()
{
    this->initWithTexture(s_image);

    this->scheduleUpdate();


    return true;
}

void Blocker::update(float delta)
{

}

