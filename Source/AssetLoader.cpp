#include <iostream>
#include "headers\AssetLoader.h"

void AssetLoader::loadFontFromFile(sf::Font& font, std::string assetName) {
	if (assetName.empty()) {
		std::cout << "ASSET NAME REQUIRED!" << std::endl;
		return;
	}

	if (!font.loadFromFile(assetName)) {
		return;
	}
}

void AssetLoader::loadSoundFromFile(sf::SoundBuffer& soundBuffer, std::string assetName) {
	if (assetName.empty()) {
		std::cout << "ASSET NAME REQUIRED!" << std::endl;
		return;
	}

	if (!soundBuffer.loadFromFile(assetName)) {
		return;
	}
}