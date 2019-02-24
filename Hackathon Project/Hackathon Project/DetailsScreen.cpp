#include "DetailsScreen.h"

DetailsScreen::DetailsScreen(GroupsTile &newTile)
{
	for (int i = 0; i < 4; i++)
		textSections[i][0].setStyle(sf::Text::Style::Bold);
	textSections[0][0].setString("Class Name:\n");
	textSections[0][0].setPosition(100, 200);
	textSections[1][0].setString("Department:\n");
	textSections[1][0].setPosition(100, 340);
	textSections[2][0].setString("Group Link:\n");
	textSections[2][0].setPosition(100, 480);
	textSections[3][0].setString("User Rating:\n");
	textSections[3][0].setPosition(100, 620);

	textSections[0][1].setString(newTile.classAbbreviation + ' ' + newTile.classNumber);
	textSections[0][1].setPosition(100, 250);
	textSections[1][1].setString(newTile.department);
	textSections[1][1].setPosition(100, 390);
	textSections[2][1].setString(newTile.contactLink);
	textSections[2][1].setPosition(100, 530);
	textSections[3][1].setString(newTile.rating);
	textSections[3][1].setPosition(100, 670);
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

}

void DetailsScreen::unloadContent()
{

}

void DetailsScreen::update(sf::RenderWindow &window, sf::Event event)
{
	input.update(event);

	if (input.mouseClick(sf::Mouse::Left))
	{
		std::cout << "Click" << std::endl;
	}
}

void DetailsScreen::draw(sf::RenderWindow &window)
{
	window.draw(backgroundSprite);
	for(int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
			window.draw(textSections[i][j]);
	}
}