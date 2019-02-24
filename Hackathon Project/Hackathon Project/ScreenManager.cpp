
#include "ScreenManager.h"

ScreenManager & ScreenManager::getInstance()
{
	static ScreenManager instance; // make it static so no error
	return instance;
}

void ScreenManager::initialize()
{
	currentScreen = new TitleScreen();
	isTransition = false;

	appScreens[0] = new TitleScreen;
	appScreens[1] = new HomeScreen;
	appScreens[2] = new myGroupsScreen;
	//appScreens[3] = new exploreGroupsScreen;
}

void ScreenManager::addScreen(Screen * screen)
{
	isTransition = true;
	newScreen = screen;
	fade.setActive(true);
	fade.setAlpha(0.0);
}

void ScreenManager::loadContent()
{
	currentScreen->loadContent();

	sf::Texture texture;
	sf::Vector2f pos;

	fade.loadContent("", texture, pos);
	fade.setAlpha(0.0);
}

void ScreenManager::unloadContent()
{
	currentScreen->unloadContent();
}

void ScreenManager::update(sf::RenderWindow & window, sf::Event event, sf::Time deltaTime)
{
	if (!isTransition)
		currentScreen->update(window, event); // then update
	transition(deltaTime);
}

void ScreenManager::draw(sf::RenderWindow &window)
{
	currentScreen->draw(window);
}

void ScreenManager::transition(sf::Time deltaTime)
{
	if (isTransition)
	{
		fade.update(deltaTime);
		if (fade.getAlpha() >= 1.0)
		{
			currentScreen->unloadContent();
			delete currentScreen; // is this really needed?
			currentScreen = newScreen;
			currentScreen->loadContent();
			newScreen = nullptr;
		}
		else if (fade.getAlpha() <= 0.0)
		{
			isTransition = false;
			fade.setActive(false);
		}
	}
}

double ScreenManager::getAlpha()
{
	return fade.getAlpha();
}


