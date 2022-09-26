#pragma once
#include <SFML/Graphics.hpp>

class Bat {
private:
	sf::Vector2f position;
	sf::RectangleShape batShape;
	float speed{ .3f };

public:
	Bat(float initialX, float initialY);
	
	sf::RectangleShape getShape();
	sf::FloatRect getPosition();

	void moveLeft();
	void moveRight();
	void update();

};