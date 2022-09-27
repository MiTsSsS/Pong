#pragma once
#include <SFML/graphics.hpp>
#include <SFML/Audio.hpp>

class AssetLoader {
private:
	std::string assetName;
	sf::Font font;
	sf::Sound sound;

public:
	void loadSoundFromFile();
	void loadFontFromFile();
};