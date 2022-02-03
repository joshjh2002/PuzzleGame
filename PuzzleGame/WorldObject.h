#pragma once
#include <SDL.h>
#include <SDL_image.h>

enum ObjectType
{
	AIR,
	WALL,
	RECEPTICAL
};

class WorldObject
{
private:
	SDL_Texture* texture;
	int x, y;
	ObjectType type;
public:
	WorldObject(int x, int y, SDL_Texture* texture, ObjectType type);
	int GetX();
	int GetY();
};

