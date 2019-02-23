#pragma once

#include "Definitions.h"
#include "InputManager.h"

// Base class for all the screens in the app


class Screen //abstract class
{
public:
	// Takes care of loading each screen's background image, buttons, etc.
	virtual void loadContent() = 0; //made this pure virtual so we can override it in future 

	// If there's anything that needs to be saved/destroyed/etc called here.
	virtual void unloadContent() = 0;

	// Moves things around, colors things, etc based on a passed in event.
	virtual void update(sf::RenderWindow &window, sf::Event event) = 0;

	// Does the drawing to the screen.
	virtual void draw(sf::RenderWindow &window) = 0;

protected:
	InputManager input;

	sf::Texture backgroundTexture; // image for background
	sf::Sprite backgroundSprite; // sprite to set background
};