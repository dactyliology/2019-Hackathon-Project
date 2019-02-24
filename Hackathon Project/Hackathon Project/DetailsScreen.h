#pragma once

#include "Screen.h"
#include "ScreenManager.h"
#include "GroupsTile.h"
#include "myGroupsScreen.h"

class DetailsScreen : public Screen
{
public:
	DetailsScreen(GroupsTile &newTile, int chooseMode);
	void loadContent();
	void unloadContent();
	void update(sf::RenderWindow &window, sf::Event event);
	void draw(sf::RenderWindow &window);

private:
	sf::Font font;
	sf::Text textSections[4][2];

	int mode;
	
	Button homeButton;
	Button addButton;
	Button backButton;

	GroupsTile tile;

};