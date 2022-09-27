#include <SFML/Graphics.hpp>
#include "headers/ball.h"

Ball::Ball(float startingX, float startingY) {
	position.x = startingX;
	position.y = startingY;

	ballShape.setSize(sf::Vector2f(10, 10));
	ballShape.setPosition(position);
}

sf::FloatRect Ball::getPosition() {
	return ballShape.getGlobalBounds();
}

sf::RectangleShape Ball::getShape() {
	return ballShape;
}

float Ball::getXVelocity() {
	return xVelocity;
}

void Ball::reboundSides() {
	xVelocity -= xVelocity * 2;
}

void Ball::reboundBatOrTop() {
	position.y -= (yVelocity * 30);
	yVelocity = -yVelocity;
}

void Ball::hitBottom() {
	position.y = 1;
	position.x = 500;
}

void Ball::update() {
	position.y += yVelocity;
	position.x += xVelocity;

	ballShape.setPosition(position);
}