#pragma once

#include "Screen.h"
#include "ScreenManager.h"

class myGroupsScreen : public Screen
{
public:
	void loadContent();
	void unloadContent();
	void update(sf::RenderWindow &window, sf::Event event);
	void draw(sf::RenderWindow &window);

private:
	void loadFileData();
	void saveFileData();

	std::fstream dataFile; // file to get and read group data




};
