#include "DetailsScreen.h"

void DetailsScreen::loadContent()
{
	// font
	if (font.loadFromFile(FONT))
		detailsText.setFont(font);
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

void DetailsScreen::getTileData(GroupsTile &newTile)
{
	tile = newTile;
}

void DetailsScreen::unloadContent()
{

}

void DetailsScreen::update(sf::RenderWindow &window, sf::Event event)
{

}

void DetailsScreen::draw(sf::RenderWindow &window)
{
	window.draw(backgroundSprite);
}