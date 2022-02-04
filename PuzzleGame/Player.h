#include <SDL.h>

#pragma once
class Player
{
private:
	
	SDL_Texture* texture;
public:
	int x, y;
	Player(SDL_Texture* texture);
	Player(int x, int y, SDL_Texture* texture);
	int GetX();
	int GetY();
	SDL_Texture* GetTexture();
};

