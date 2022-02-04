#include "WorldObject.h"

WorldObject::WorldObject(int x, int y, SDL_Texture* texture, ObjectType type)
{
	this->x = x;
	this->y = y;
	this->texture = texture;
	this->type = type;
}

int WorldObject::GetX() {
	return this->x;
}

int WorldObject::GetY() {
	return this->y;
}

SDL_Texture* WorldObject::GetTexture()
{
	return this->texture;
}