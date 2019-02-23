#pragma once

#include "Screen.h"
#include "HomeScreen.h"


class TitleScreen : public Screen
{
public:
	void loadContent();
	void unloadContent();
	void update(sf::RenderWindow &window, sf::Event event);
	void draw(sf::RenderWindow & window);

private:
	// perhaps a single sign in button?
};