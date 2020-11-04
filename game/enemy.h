#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "random.h"
class enemy
{
public:
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;
	int movementspeed = 0;
	int attackDamage = 1;
	int direction;
	int hp = 3;
	bool alive = true;



	enemy();
	void update();
	void updateMovement();
};



