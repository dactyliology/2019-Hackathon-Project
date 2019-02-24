#pragma once

#include "Screen.h"
#include "ScreenManager.h"
#include "GroupsTile.h"

class DetailsScreen : public Screen
{
public:
	void loadContent();
	void getTileData(GroupsTile &newTile);
	void unloadContent();
	void update(sf::RenderWindow &window, sf::Event event);
	void draw(sf::RenderWindow &window);

private:
	sf::Font font;
	sf::Text detailsText;

	GroupsTile tile;

};