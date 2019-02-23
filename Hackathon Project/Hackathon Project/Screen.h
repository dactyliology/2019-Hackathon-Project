#pragma once

#include "Definitions.h"

// Base class for all the screens in the app


class Screen
{
public:
	// Takes care of loading each screen's background image, buttons, etc.
	virtual void loadContent();

	// If there's anything that needs to be saved/destroyed/etc called here.
	virtual void unloadContent();

	// Moves things around, colors things, etc based on a passed in event.
	virtual void update(sf::RenderWindow &window, sf::Event event);

	// Does the drawing to the screen.
	virtual void draw(sf::RenderWindow &window);

private:
	sf::Texture backgroundTexture; // image for background
	sf::Sprite backgroundSprite; // sprite to set background
};