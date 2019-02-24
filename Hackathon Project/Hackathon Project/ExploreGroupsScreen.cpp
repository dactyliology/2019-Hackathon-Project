#include "ExploreGroupsScreen.h"

void ExploreGroupsScreen::loadContent()
{
	if (backgroundTexture.loadFromFile(EXPLOREGROUPS_SCREEN))
	{
		backgroundTexture.setSmooth(true);
		backgroundSprite.setTexture(backgroundTexture);
	}
	else
		std::cout << "Cannot load explore groups screen" << std::endl;

	loadFileData();

	// set tile images & tileText
	for (int i = 0; i < tilesLibrary.size(); i++)
		tilesLibrary[i].loadContent();

	// set tile positions & tileText positions
	for (int i = 0; i < tilesLibrary.size(); i++)
	{
		tilesLibrary[i].setPositionFromArrayIndex(i, GAP, 250);

		// center text on tile
		tilesLibrary[i].tileText.setPosition(tilesLibrary[i].getPosition().x, tilesLibrary[i].getPosition().y + 30);
	}

	homeButton.loadContent(HOME_BUTTON);
	homeButton.setPosition(450, 25);
}

void ExploreGroupsScreen::unloadContent()
{

}

void ExploreGroupsScreen::update(sf::RenderWindow &window, sf::Event event)
{
	input.update(event);

	// if a tile is hovered, change it's color
	for (int i = 0; i < tilesLibrary.size(); i++)
	{
		if (input.mouseHover(tilesLibrary[i], window))
			tilesLibrary[i].setColor(BUTTON_HOVER_COLOR);
		else
			tilesLibrary[i].setColor(BUTTON_ORIGINAL_COLOR);
	}

	// if a tile is clicked, open details page
	for (int i = 0; i < tilesLibrary.size(); i++)
	{
		if (input.mouseClick(sf::Mouse::Left) && input.mouseHover(tilesLibrary[i], window))
		{
			ScreenManager::getInstance().addScreen(new DetailsScreen(tilesLibrary[i], 1)); 
		}
	}

	// if home button is clicked, go back to home page
	if (input.mouseClick(sf::Mouse::Left) && input.mouseHover(homeButton, window))
	{
		ScreenManager::getInstance().addScreen(new HomeScreen);
	}
}

void ExploreGroupsScreen::draw(sf::RenderWindow &window)
{
	window.draw(backgroundSprite);
	displayTiles(window);
	window.draw(homeButton);
}

void ExploreGroupsScreen::loadFileData()
{
	dataFile.open("TileLibrary.txt");

	GroupsTile newTile;

	while (!dataFile.eof())
	{
		dataFile >> newTile;
		tilesLibrary.push_back(newTile);
	}

	dataFile.close();

}

void ExploreGroupsScreen::displayTiles(sf::RenderWindow &window)
{
	for (int i = 0; i < tilesLibrary.size(); i++)
	{
		window.draw(tilesLibrary[i]);
		window.draw(tilesLibrary[i].tileText);
	}
}