#include "Player.h"

Player::Player(SDL_Texture* texture)
{
	this->texture = texture;
}

Player::Player(int x, int y, SDL_Texture* texture)
{
	this->texture = texture;
	this->x = x;
	this->y = y;
}

int Player::GetX() { return this->x; }

int Player::GetY() { return this->y; }

SDL_Texture* Player::GetTexture() { return this->texture; }