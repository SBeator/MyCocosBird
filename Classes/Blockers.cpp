#include "Blockers.h"

USING_NS_CC;

bool Blockers::init()
{
    _gameManager = GameManager::getInstance();

    this->addRandomBlocker();

    _blockerCreateTime = 2;
    this->scheduleUpdate();

    return true;
}

bool Blockers::hitBird(Bird* bird)
{
    bool hit = false;
    for (auto blocker : _blockers)
    {
        if (blocker->hitBird(bird))
        {
            hit = true;
            break;
        }
    }

    return hit;
}

void Blockers::addRandomBlocker()
{
    auto point = _gameManager->getGameCenter();

    auto size = _gameManager->getGamePlaceSize();
    auto offset = _gameManager->getRandomNumber(size.height / 2 * 0.6, -size.height / 2 * 0.6);

    auto blocker = Blocker::create();
    blocker->setPosition(point + Point(size.width / 2 + blocker->getWidth(), offset));

    this->addBlocker(blocker);
}

void Blockers::addBlocker(Blocker* blocker)
{
    _blockers.pushBack(blocker);
    this->addChild(blocker);
}

float updateTime = 0;
void Blockers::update(float delta)
{
    updateTime += delta;

    if (updateTime > _blockerCreateTime)
    {
        this->addRandomBlocker();
        this->removeBlockerIfOut();
        updateTime = 0;
    }
}

void Blockers::removeBlockerIfOut()
{
    auto blocker = _blockers.at(0);

    if (blocker != nullptr)
    {
        auto point = _gameManager->getGameCenter();
        auto size = _gameManager->getGamePlaceSize();
        auto position = blocker->getPosition();
        auto width = blocker->getWidth();

        if (point.x - position.x + width > size.width / 2)
        {
            this->removeChild(blocker);
            _blockers.erase(0);
        }
    }
    else
    {
        _blockers.erase(0);
    }
}

