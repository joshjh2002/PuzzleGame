#pragma once
#include "WorldObject.h"
#include "Player.h"
#include <vector>
#include <iostream>

class Game
{
private:
	WorldObject*** map;
	Player * player;
	int mapWidth;
	int mapHeight;
	int blockSize;
public:
	Game(int mapX, int mapY, int screenWidth, int screenHeight, Player* player);
	void DrawMap(SDL_Renderer* renderer);
	int GetBlockSize();
};

