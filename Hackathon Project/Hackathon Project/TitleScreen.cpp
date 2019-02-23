#include "TitleScreen.h"

void TitleScreen::loadContent()
{
	if (backgroundTexture.loadFromFile(TITLESCREEN))
	{
		backgroundTexture.setSmooth(true); // makes the image looks nicer by smoothing it
		backgroundSprite.setTexture(backgroundTexture);
	}
	else
		std::cout << "TitleScreen image couldn't load" << std::endl; 
}

void TitleScreen::unloadContent()
{
	
}

void TitleScreen::update(sf::RenderWindow &window, sf::Event event)
{

}

void TitleScreen::draw(sf::RenderWindow & window)
{
	window.draw(backgroundSprite);
}