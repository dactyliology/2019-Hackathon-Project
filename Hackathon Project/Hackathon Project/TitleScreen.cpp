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
	input.update(event);

	if (input.mouseClick(sf::Mouse::Button::Left)) // if user clicks left mouse
	{
		Screen *nextScreen = ScreenManager::getInstance().appScreens[1]; // home screen
		ScreenManager::getInstance().addScreen(nextScreen);
	}
}

void TitleScreen::draw(sf::RenderWindow & window)
{
	window.draw(backgroundSprite);
}