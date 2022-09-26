#include <M:\GameDevelopment\VS-Projects\Pong\bat.h>

Bat::Bat(float x, float y) {
	position.x = x;
	position.y = y;

	batShape.setSize(sf::Vector2f(50, 5));
	batShape.setPosition(position);

}

sf::FloatRect Bat::getPosition() {
	return batShape.getGlobalBounds();

}

sf::RectangleShape Bat::getShape() {
	return batShape;

}

void Bat::moveLeft() {
	position.x -= speed;

}

void Bat::moveRight() {
	position.x += speed;

}

void Bat::update() {
	batShape.setPosition(position);

}