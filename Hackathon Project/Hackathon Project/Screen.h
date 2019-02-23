#pragma once

#include "Definitions.h"

// Base class for all the screens in the app


class screen
{
public:
	virtual void loadContent();
	virtual void unloadContent();
	virtual void update(sf::RenderWindow &window, sf::Event event);
};