#include "Blockers.h"

USING_NS_CC;

bool Blockers::init()
{
    _gameManager = GameManager::getInstance();

    _Blockers = new Vector<Blocker*>();

    this->addRandomBlocker();

    _blockerCreateTime = 2;
    this->scheduleUpdate();

    return true;
}

void Blockers::addRandomBlocker()
{
    auto point = _gameManager->getGameCenter();

    auto size = _gameManager->getGamePlaceSize();
    auto offset = _gameManager->getRandomNumber(size.height * 0.6, -size.height * 0.6);

    auto blocker = Blocker::create();
    blocker->setPosition(point + Point(size.width + blocker->getWidth(), offset));

    this->addBlocker(blocker);
}

void Blockers::addBlocker(Blocker* blocker)
{
    _Blockers->pushBack(blocker);
    this->addChild(blocker);
}

float updateTime = 0;
void Blockers::update(float delta)
{
    updateTime += delta;

    if (updateTime > _blockerCreateTime)
    {
        this->addRandomBlocker();
        updateTime = 0;
    }
}