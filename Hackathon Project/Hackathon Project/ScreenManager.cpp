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
	fade.setAlpha(0.0);

}

void ScreenManager::unloadContent()
{
	currentScreen->unloadContent();
}

void ScreenManager::update(sf::RenderWindow &window, sf::Event event, sf::Time deltaTime)
{
	if (!isTransition)
		currentScreen->update(window, event); // then update
	transition(deltaTime);
}

void ScreenManager::draw(sf::RenderWindow &window)
{
	currentScreen->draw(window);
}

void ScreenManager::addScreen(Screen *newScreen)
{
	isTransition = true;
	addedScreen = newScreen;
	fade.setActive(true);
	fade.setAlpha(0.0);
}

void ScreenManager::transition(sf::Time deltaTime)
{
	if (isTransition)
	{
		fade.update(deltaTime);
		if (fade.getAlpha() >= 1.0)
		{
			currentScreen->unloadContent();
			delete currentScreen; 
			currentScreen = addedScreen;
			currentScreen->loadContent();
			addedScreen = nullptr;
		}
		else if (fade.getAlpha() <= 0.0)
		{
			isTransition = false;
			fade.setActive(false);
		}
	}
}

float ScreenManager::getAlpha()
{
	return fade.getAlpha();
}
