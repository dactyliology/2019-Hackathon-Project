#pragma once

#include "Screen.h"
#include "ScreenManager.h"
#include "GroupsTile.h"

class DetailsScreen : public Screen
{
public:
	DetailsScreen(GroupsTile &newTile);
	void loadContent();
	void unloadContent();
	void update(sf::RenderWindow &window, sf::Event event);
	void draw(sf::RenderWindow &window);

private:
	sf::Font font;
	sf::Text textSections[4][2];
	
	Button homeButton;
	Button backButton;

};