#include "myGroupsScreen.h"

void myGroupsScreen::loadContent()
{
	// load background image
	if (backgroundTexture.loadFromFile(MYGROUPS_SCREEN))
	{
		backgroundTexture.setSmooth(true);
		backgroundSprite.setTexture(backgroundTexture);
	}
	else
		std::cout << "Could not load myScreen background" << std::endl;

	// reads file data into the vector of tiles
	loadFileData();

	// set tile images
	for (int i = 0; i < myGroupsTiles.size(); i++)
		myGroupsTiles[i].loadContent();

	// set tile positions
	for (int i = 0; i < myGroupsTiles.size(); i++)
		myGroupsTiles[i].setPositionFromArrayIndex(i, GAP, OFFSET);
}

void myGroupsScreen::unloadContent()
{
	saveFileData(); // save the data when closing the screen
}

void myGroupsScreen::update(sf::RenderWindow &window, sf::Event event)
{
	input.update(event);

	// if a tile is hovered, change it's color
	for (int i = 0; i < myGroupsTiles.size(); i++)
	{
		if (input.mouseHover(myGroupsTiles[i], window))
			myGroupsTiles[i].setColor(BUTTON_HOVER_COLOR);
		else
			myGroupsTiles[i].setColor(BUTTON_ORIGINAL_COLOR);
	}


	// if a tile is clicked, open details page

	// implement scrolling if page gets too long
}

void myGroupsScreen::draw(sf::RenderWindow &window)
{
	window.draw(backgroundSprite);
	displayTiles(window);
}

void myGroupsScreen::loadFileData()
{
	dataFile.open("myGroupsData.txt");

	GroupsTile newTile;

	while (!dataFile.eof())
	{
		dataFile >> newTile;
		myGroupsTiles.push_back(newTile);
	}

	dataFile.close();
}

void myGroupsScreen::saveFileData()
{
	dataFile.open("myGroupsData.txt");

	for (int i = 0; i < myGroupsTiles.size(); i++)
		dataFile << myGroupsTiles[i];

	dataFile.close();
}

void myGroupsScreen::displayTiles(sf::RenderWindow &window)
{
	for (int i = 0; i < myGroupsTiles.size(); i++)
		window.draw(myGroupsTiles[i]);
}