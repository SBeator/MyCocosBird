#include "GameManager.h"

GameManager* GameManager::_gameManager;

GameManager* GameManager::getInstance()
{
	if (!_gameManager)
	{
		_gameManager = new GameManager();
		_gameManager->init();
	}

	return _gameManager;
}

bool GameManager::init()
{
	return true;
}