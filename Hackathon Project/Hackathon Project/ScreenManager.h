#pragma once

#include "TitleScreen.h"
#include "HomeScreen.h"
#include "myGroupsScreen.h"
#include "DetailsScreen.h"
#include "ExploreGroupsScreen.h"

#define SCREEN_WIDTH 508
#define SCREEN_HEIGHT 900

class ScreenManager
{
public:
	static ScreenManager & getInstance(); // Can only make one instantiation since static

	void initialize();
	void loadContent();
	void unloadContent();
	void update(sf::RenderWindow & window, sf::Event event, sf::Time deltaTime);
	void draw(sf::RenderWindow &window);

	void addScreen(Screen *screen);

	double getAlpha();
	void alphaReset();
	

protected:
private:
	Screen *currentScreen, *newScreen; // will be using polymorphism

	void transition(sf::Time deltaTime);
	bool isTransition;

	FadeAnimation fade;

};
