#pragma once

#include "Definitions.h"

class Button : public sf::Sprite
{
public:
	void loadContent(std::string filename);

private:
	sf::Texture buttonImage;
};