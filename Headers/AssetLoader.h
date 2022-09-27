#pragma once
#include <SFML/graphics.hpp>
#include <SFML/Audio.hpp>

class AssetLoader {
public:
	void loadFontFromFile(sf::Font&, std::string);
	void loadSoundFromFile(sf::SoundBuffer&, std::string);
};