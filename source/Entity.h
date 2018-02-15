#pragma once
#include <SFML/Graphics.hpp>

class Entity : public sf::Sprite
{
protected:
	sf::IntRect _sprite;
	Entity();
public:
	//virtual void Update(const float &dt);
	explicit Entity(sf::IntRect it);
	virtual ~Entity() = 0;
};

class Player : public Entity 
{
public:
//	static float speed;
	void Update(const float &dt);
	Player();
};