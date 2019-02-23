#pragma once

#include "Screen.h"
#include "ScreenManager.h"
#include "GroupsTile.h"

#define GAP 49
#define OFFSET 100

// class for the myGroups page. When a tile from the library is selected to be added to myGroups,
// the interface needs to update to account for that.

class myGroupsScreen : public Screen
{
public:
	void loadContent();
	void unloadContent();
	void update(sf::RenderWindow &window, sf::Event event);
	void draw(sf::RenderWindow &window);

private:
	// Reads all tiles from data file;
	void loadFileData();

	// Writes all the tiles to a data file
	void saveFileData();

	void displayTiles(sf::RenderWindow &window);

	std::fstream dataFile; // file to get and read group data

	std::vector<GroupsTile> myGroupsTiles;




};
