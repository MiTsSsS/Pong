#include "headers/bat.h"
#include "headers/ball.h"
#include "headers/AssetLoader.h"
#include <iostream>
#include <sstream>
//#include <SFML/Audio.hpp>
//#include <SFML/Graphics.hpp>

int main() {
	int windowHeight = 768;
	int windowWidth = 1024;

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Pong");
	window.setFramerateLimit(60);

	int score = 0;
	int lives = 3;

	Bat bat(windowWidth / 2, windowHeight - 20);
	Ball ball(windowWidth / 2, 1);
	AssetLoader assetLoader;

	sf::Text scoreCounter;
	sf::Text livesCounter;
	
	sf::Font font;
	assetLoader.loadFontFromFile(font, "Assets\\Fonts\\DS-DIGIT.ttf");

	scoreCounter.setFont(font);
	scoreCounter.setCharacterSize(75);
	scoreCounter.setFillColor(sf::Color::White);

	livesCounter.setFont(font);
	livesCounter.setCharacterSize(75);
	livesCounter.setPosition(760, 0);
	livesCounter.setFillColor(sf::Color::White);
	
	livesCounter.setString("Lives: " + std::to_string(lives));
	scoreCounter.setString("Score: " + std::to_string(score));

	sf::Sound sound;
	sf::SoundBuffer hitPaddle;
	sf::SoundBuffer hitWall;
	sf::SoundBuffer lose;

	assetLoader.loadSoundFromFile(hitPaddle, "Assets\\Sounds\\HitPaddle.wav");
	assetLoader.loadSoundFromFile(hitWall, "Assets\\Sounds\\HitWall.wav");
	assetLoader.loadSoundFromFile(lose, "Assets\\Sounds\\Lose.wav");

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
			sound.setBuffer(lose);
			sound.play();

			lives--;
			livesCounter.setString("Lives: " + std::to_string(lives));

			if (lives < 1) {
				score = 0;
				lives = 3;

				livesCounter.setString("Lives: " + std::to_string(lives));
				scoreCounter.setString("Score: " + std::to_string(score));
			}
		}

		if (ball.getPosition().top < 0) {
			sound.setBuffer(hitPaddle);
			sound.play();

			ball.reboundBatOrTop();
			score++;
			scoreCounter.setString("Score: " + std::to_string(score));
		}
		
		//Left + 10 cause getPosition().left returns the left coordinate of the triangle and 10 is the width of the triangle.
		if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth) { 
			sound.setBuffer(hitWall);
			sound.play();

			ball.reboundSides();
		}

		if (ball.getPosition().intersects(bat.getPosition())) {
			sound.setBuffer(hitPaddle);
			sound.play();

			ball.reboundBatOrTop();
		}

		ball.update();
		bat.update();

		window.clear(sf::Color(26, 128, 182, 255));
		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.draw(scoreCounter);
		window.draw(livesCounter);

		window.display();
	}

	return 0;
}