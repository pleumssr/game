#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class player
{
public:
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;
	int movementspeed = 0;
	int attack = 5;
	int direction = 0;
	int hp = 10;

	player();
	void update();
	void updateMovement();
private:
protected:
};



