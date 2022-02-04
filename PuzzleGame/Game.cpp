#include "Game.h"

Game::Game(int mapX, int mapY, int screenWidth, int screenHeight, Player* player)
{
	if (mapY >= mapX)
	{
		blockSize = screenHeight / mapY;
	}
	else
	{
		blockSize = screenWidth / mapX;
	}

	mapHeight = mapY;
	mapWidth = mapX;

	map = (WorldObject***)malloc(sizeof(WorldObject**) * mapX);
	for (int k = 0; k < mapX; k++) {
		map[k] = (WorldObject**)malloc(sizeof(WorldObject*) * mapY);
	}

	this->player = player;
	for (int x = 0; x < mapX; x++)
	{
		for (int y = 0; y < mapY; y++)
		{
			map[x][y] = new WorldObject(x * blockSize, y * blockSize, NULL, ObjectType::AIR);
		}
	}
}

void Game::DrawMap(SDL_Renderer* renderer)
{
	SDL_Rect rect = { 0,0,blockSize, blockSize };
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	int counter = 0;
	for (int x = 0; x < mapWidth; x++)
	{
		for (int y = 0; y < mapHeight; y++)
		{
			if (counter % 2 == 0)
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			else
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			counter++;
			 rect.x = map[x][y]->GetX();
			 rect.y = map[x][y]->GetY();
			 
			 SDL_RenderFillRect(renderer, &rect);

		}
		if (mapHeight % 2 == 0)
			counter++;
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	rect.x = player->GetX();
	rect.y = player->GetY();
	SDL_RenderCopy(renderer, player->GetTexture(), NULL, &rect);
}

int Game::GetBlockSize() {
	return this->blockSize;
}