#include "myGroupsScreen.h"

myGroupsScreen::myGroupsScreen()
{

}

myGroupsScreen::myGroupsScreen(GroupsTile & newTile)
{
	myGroupsTiles.push_back(newTile);
}


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

	// set tile images & tileText
	for (int i = 0; i < myGroupsTiles.size(); i++)
		myGroupsTiles[i].loadContent();

	// set tile positions & tileText positions
	for (int i = 0; i < myGroupsTiles.size(); i++)
	{
		myGroupsTiles[i].setPositionFromArrayIndex(i, GAP, OFFSET);

		// center text on tile
		myGroupsTiles[i].tileText.setPosition(myGroupsTiles[i].getPosition().x, myGroupsTiles[i].getPosition().y + 30);
	}

	homeButton.loadContent(HOME_BUTTON);
	homeButton.setPosition(450, 25);

	myGroupsHeader.loadContent(MYGROUPS_HEADER);

	view.setSize(508, 900);
	view.setCenter(254, 450);
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
	for (int i = 0; i < myGroupsTiles.size(); i++)
	{
		if (input.mouseClick(sf::Mouse::Left) && input.mouseHover(myGroupsTiles[i], window))
		{
			ScreenManager::getInstance().addScreen(new DetailsScreen(myGroupsTiles[i], 0));
		}
	}

	// if home button is clicked, go back to home page
	if (input.mouseClick(sf::Mouse::Left) && input.mouseHover(homeButton, window))
	{
		ScreenManager::getInstance().addScreen(new HomeScreen);
	}

	// implement scrolling if page gets too long

	if (myGroupsTiles.size() > 6)
	{
		sf::Vector2i coordsPos = window.mapCoordsToPixel(backgroundSprite.getPosition());

		if (sf::Mouse::getPosition(window).y < 100
			&& sf::Mouse::getPosition(window).y > 0
			&& coordsPos.y <= 0)
		{
			view.move(0, -0.25); // moves up
			homeButton.move(0, -0.25);
			myGroupsHeader.move(0, -0.25);
		}
		else if (sf::Mouse::getPosition(window).y > 800
			&& coordsPos.y > -1 * (myGroupsTiles[myGroupsTiles.size() - 1].getPosition().y + myGroupsTiles[0].getGlobalBounds().height) + 850)
		{
			view.move(0, 0.25); // move down
			homeButton.move(0, 0.25);
			myGroupsHeader.move(0, 0.25);
		}
	}

}

void myGroupsScreen::draw(sf::RenderWindow &window)
{
	window.draw(backgroundSprite);
	displayTiles(window);
	window.setView(view);
	window.draw(myGroupsHeader);
	window.draw(homeButton);
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
	{
		if (i == myGroupsTiles.size() - 1)
			dataFile << myGroupsTiles[i];
		else
			dataFile << myGroupsTiles[i] << std::endl; // prevent extra newline at the end
	}

	dataFile.close();
}

void myGroupsScreen::displayTiles(sf::RenderWindow &window)
{
	for (int i = 0; i < myGroupsTiles.size(); i++)
	{
		window.draw(myGroupsTiles[i]);
		window.draw(myGroupsTiles[i].tileText);
	}
}