#include "game.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

Texture spritesheet;
Player* plays;
auto p = new Player();

void Load()
{
	plays = p;
	//Player::speed = 100.0f;
}

void Update(RenderWindow &window)
{
	static Clock clock;
	float dt = clock.restart().asSeconds();
	Event eve;
	while (window.pollEvent(eve))
	{
		if (eve.type == Event::Closed)
		{
			window.close();
			return;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape))
		window.close();
	plays->Update(dt);
}

void Render(RenderWindow &window)
{
	window.draw(*p);
}

int main()
{
	RenderWindow window(VideoMode(gameWidth, gameHeight), "Project");

	while (window.isOpen())
	{
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}
