#include "Entity.h"
#include "game.h"

using namespace std;
using namespace sf;

Entity::Entity() {};

Entity::~Entity() = default;

Entity::Entity(IntRect ir) : Sprite()
{
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
}

Player::Player() : Entity(IntRect(32, 32, 32, 32))
{
	setPosition(gameWidth * .5f, gameHeight * .5f);
}

void Player::Update(const float &dt)
{
	float speed = 100.f;
	//Entity::Update(dt);
	float vertical = .0f;
	float horizontal = .0f;

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		horizontal--;
		plays->move(horizontal*dt*speed, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		horizontal++;
		plays->move(horizontal*dt*speed, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		vertical--;
		plays->move(0, vertical*dt*speed);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		vertical++;
		plays->move(0, vertical*dt*speed);
	}
}