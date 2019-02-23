#pragma once

#include "Definitions.h"

class InputManager
{
public:
	void loadContent(sf::Event newEvent);

	bool mouseClick(sf::Mouse::Button button);
	bool mouseHover(sf::Sprite &object, sf::RenderWindow &window);
	bool mouseScroll(sf::Mouse::Wheel wheel);

private:
	sf::Event event;
};

