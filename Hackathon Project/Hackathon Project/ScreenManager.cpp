#include "ScreenManager.h"

ScreenManager & ScreenManager::getInstance()
{
	static ScreenManager newInstance;
	return newInstance;
}

void ScreenManager::initialize()
{
	currentScreen = new TitleScreen;
}

void ScreenManager::loadContent()
{
	currentScreen->loadContent();

}

void ScreenManager::unloadContent()
{
	currentScreen->unloadContent();
}

void ScreenManager::update(sf::RenderWindow &window, sf::Event, sf::Time deltaTime)
{

}

void ScreenManager::draw(sf::RenderWindow &window)
{
	currentScreen->draw(window);
}

void ScreenManager::addScreen(Screen *newScreen)
{
	addedScreen = newScreen;
}

void ScreenManager::transition(sf::Time deltaTime)
{
	if (isTransition)
	{

	}
}
