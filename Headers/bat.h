#pragma once
#include <SFML/Graphics.hpp>

class Bat {
private:
	sf::Vector2f position;
	sf::RectangleShape batShape;
	float speed{ 10.5f };

public:
	Bat(float startingX, float startingY);
	
	sf::RectangleShape getShape();
	sf::FloatRect getPosition();

	void moveLeft();
	void moveRight();
	void update();
};