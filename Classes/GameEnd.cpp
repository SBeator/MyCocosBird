#include "GameEnd.h"
#include "GameRunning.h"

USING_NS_CC;

std::string GameEnd::s_gameOverLabelPath = "GameOverLabel.png";
std::string GameEnd::s_continuePath = "Continue.png";
std::string GameEnd::s_continuePressedPath = "Continue_Press.png";

bool GameEnd::init()
{
    if (!Layer::init())
    {
        return false;
    }

    auto gameManager = GameManager::getInstance();
    auto center = gameManager->getGameCenter();
    auto size = gameManager->getGamePlaceSize();

    _gameOverLabel = Sprite::create(s_gameOverLabelPath);
    _gameOverLabel->setPosition(Point(center.x, center.y + size.height / 5));
    this->addChild(_gameOverLabel, 0);

    auto continueItem = MenuItemImage::create(
        s_continuePath,
        s_continuePressedPath,
        CC_CALLBACK_0(GameEnd::continueGame, this));

    continueItem->setPosition(Point(center.x, center.y - size.height / 5));

    // create menu, it's an autorelease object
    auto menu = Menu::create(continueItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    return true;
}

void GameEnd::continueGame()
{
    GameManager::getInstance()->startGame();
}