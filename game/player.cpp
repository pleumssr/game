#include "player.h"

player::player()
{
	rect.setSize(sf::Vector2f(116, 116));
	rect.setPosition(400, 200);
	rect.setFillColor(sf::Color::Blue);
	sprite.setTextureRect(sf::IntRect(0, 0, 116, 116));

}

void player::update()
{
	sprite.setPosition(rect.getPosition().x, rect.getPosition().y);
}

void player::updateMovement()
{
	if (movementspeed == 3)movementspeed = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		rect.move(-0.1, 0);
		sprite.setTextureRect(sf::IntRect(movementspeed * 116, 116 * 1, 116, 116));
		direction = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		rect.move(0.1, 0);
		sprite.setTextureRect(sf::IntRect(movementspeed * 116, 116 * 2, 116, 116));
		direction = 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		rect.move(0, -0.1);
		sprite.setTextureRect(sf::IntRect(movementspeed * 116, 116 * 3, 116, 116));
		direction = 3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		rect.move(0, 0.1);
		sprite.setTextureRect(sf::IntRect(movementspeed * 116, 116 * 0, 116, 116));
		direction = 4;
	}
	movementspeed++;

}

