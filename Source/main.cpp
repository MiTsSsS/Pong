#include "headers/bat.h"
#include "headers/ball.h"
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>

int main() {
	int windowHeight = 768;
	int windowWidth = 1024;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Pong");

	int score = 0;
	int lives = 3;

	Bat bat(windowWidth / 2, windowHeight - 20);
	Ball ball(windowWidth / 2, 1);

	sf::Text hud;
	
	sf::Font font;
	if (!font.loadFromFile("Assets\\Fonts\\DS-DIGIT.ttf"))
	{
		std::cout << "ERROR LOADING FONT... " << std::endl;
		return -1;
	}

	hud.setFont(font);
	hud.setCharacterSize(75);
	hud.setFillColor(sf::Color::White);

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			bat.moveLeft();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			bat.moveRight();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window.close();
		}

		if (ball.getPosition().top > windowHeight) {
			ball.hitBottom();

			lives--;
			if (lives < 1) {
				score = 0;
				lives = 3;
			}
		}

		if (ball.getPosition().top < 0) {
			ball.reboundBatOrTop();
			score++;
		}
		
		//Left + 10 cause getPosition().left returns the left coordinate of the triangle and 10 is the width of the triangle.
		if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth) { 
			ball.reboundSides();
		}

		if (ball.getPosition().intersects(bat.getPosition())) {
			ball.reboundBatOrTop();
		}

		ball.update();
		bat.update();

		std::stringstream ss;
		ss << "Score:" << score << "\t\t\t\t\t\t\t  Lives:" << lives;
		hud.setString(ss.str());

		window.clear(sf::Color(26, 128, 182, 255));
		
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.draw(hud);

		window.display();
	}

	return 0;
}