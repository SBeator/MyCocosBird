#pragma once
class GameManager
{
public:
	static GameManager* getInstance();

	bool init();

private:
	static GameManager* _gameManager;
};

