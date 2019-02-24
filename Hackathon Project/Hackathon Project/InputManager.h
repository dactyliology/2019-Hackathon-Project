#pragma once

#include "Definitions.h"

class InputManager
{
public:
	void update(sf::Event newEvent);

	bool mouseClick(sf::Mouse::Button button);
	bool mouseHover(sf::Sprite &object, sf::RenderWindow &window);

private:
	sf::Event event;
};

