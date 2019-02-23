#pragma once

#include "Screen.h"


class HomeScreen : public Screen
{
public:
	void loadContent();
	void unloadContent();
	void update(sf::RenderWindow &window, sf::Event event);
	void draw(sf::RenderWindow &window);

private:
	Button myGroupsButton;
	Button exploreButton;

};