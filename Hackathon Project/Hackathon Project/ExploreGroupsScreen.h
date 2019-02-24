#pragma once

#include "ScreenManager.h"
#include "Screen.h"
#include "GroupsTile.h"

class ExploreGroupsScreen : public Screen
{
public:
	void loadContent();
	void unloadContent();
	void update(sf::RenderWindow &window, sf::Event event);
	void draw(sf::RenderWindow &window);

private:
	void loadFileData();
	void displayTiles(sf::RenderWindow &window);

	std::fstream dataFile;

	std::vector<GroupsTile> tilesLibrary;

	sf::View view;

	Button homeButton;
	Button exploreGroupsHeader;
};