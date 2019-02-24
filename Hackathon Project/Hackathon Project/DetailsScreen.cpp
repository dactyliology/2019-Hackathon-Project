#include "DetailsScreen.h"

DetailsScreen::DetailsScreen(GroupsTile &newTile, int chooseMode)
{
	for (int i = 0; i < 4; i++)
		textSections[i][0].setStyle(sf::Text::Style::Bold);
	textSections[0][0].setString("Class Name:\n");
	textSections[0][0].setPosition(100, 220);
	textSections[1][0].setString("Department:\n");
	textSections[1][0].setPosition(100, 360);
	textSections[2][0].setString("Group Link:\n");
	textSections[2][0].setPosition(100, 500);
	textSections[3][0].setString("User Rating:\n");
	textSections[3][0].setPosition(100, 640);

	textSections[0][1].setString(newTile.classAbbreviation + ' ' + newTile.classNumber);
	textSections[0][1].setPosition(100, 270);
	textSections[1][1].setString(newTile.department);
	textSections[1][1].setPosition(100, 410);
	textSections[2][1].setString(newTile.contactLink);
	textSections[2][1].setPosition(100, 550);
	textSections[3][1].setString(newTile.rating);
	textSections[3][1].setPosition(100, 690);

	mode = chooseMode;

	tile = newTile;
}


void DetailsScreen::loadContent()
{
	// font
	if (font.loadFromFile(FONT))
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				textSections[i][j].setFont(font);
				textSections[i][j].setColor(sf::Color::Black);
				textSections[i][j].setCharacterSize(36);
			}
		}

		textSections[2][1].setColor(sf::Color::Blue);

	}
	else
		std::cout << "Could not load details font" << std::endl;

	// background
	if (backgroundTexture.loadFromFile(DETAILS_SCREEN))
	{
		backgroundTexture.setSmooth(true);
		backgroundSprite.setTexture(backgroundTexture);
	}
	else
		std::cout << "Could not load details screen background" << std::endl;

	homeButton.loadContent(HOME_BUTTON);
	backButton.loadContent(BACK_BUTTON);

	homeButton.setPosition(450, 25);

	if (mode == 1)
	{
		addButton.loadContent(ADD_BUTTON);
		addButton.setPosition(275, 800);
		backButton.setPosition(100, 800);
	}
	else if (mode == 0)
		backButton.setPosition(199, 800);

}

void DetailsScreen::unloadContent()
{

}

void DetailsScreen::update(sf::RenderWindow &window, sf::Event event)
{
	input.update(event);

	if (input.mouseClick(sf::Mouse::Left) && input.mouseHover(homeButton, window))
		ScreenManager::getInstance().addScreen(new HomeScreen);
	if (input.mouseClick(sf::Mouse::Left) && input.mouseHover(backButton, window))
			ScreenManager::getInstance().addScreen(new ExploreGroupsScreen);
	if (mode == 1)
		if (input.mouseClick(sf::Mouse::Left) && input.mouseHover(addButton, window))
			ScreenManager::getInstance().addScreen(new myGroupsScreen(tile));
}

void DetailsScreen::draw(sf::RenderWindow &window)
{
	window.draw(backgroundSprite);
	for(int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
			window.draw(textSections[i][j]);
	}
	window.draw(homeButton);
	window.draw(backButton);
	if (mode == 1)
		window.draw(addButton);
}