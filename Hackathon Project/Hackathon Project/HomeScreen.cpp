#include "HomeScreen.h"

void HomeScreen::loadContent()
{
	// set background image
	if (backgroundTexture.loadFromFile(HOMESCREEN))
	{
		backgroundTexture.setSmooth(true);
		backgroundSprite.setTexture(backgroundTexture);
	}
	else
		std::cout << "Homescreen background couldn't load" << std::endl;

	// load button images
	myGroupsButton.loadContent(MYGROUPS_BUTTON);
	exploreButton.loadContent(EXPLORE_BUTTON);

	// set button position
	myGroupsButton.setPosition(104, 150);
	exploreButton.setPosition(104, 520);
}

void HomeScreen::unloadContent()
{

}

void HomeScreen::update(sf::RenderWindow &window, sf::Event event)
{
	input.update(event);

	// if a button is hovered, change the color
	if (input.mouseHover(myGroupsButton, window))
		myGroupsButton.setColor(BUTTON_HOVER_COLOR);
	else
		myGroupsButton.setColor(BUTTON_ORIGINAL_COLOR);

	if (input.mouseHover(exploreButton, window))
		exploreButton.setColor(BUTTON_HOVER_COLOR);
	else
		exploreButton.setColor(BUTTON_ORIGINAL_COLOR);


	// buttons are clicked...
	if (input.mouseClick(sf::Mouse::Button::Left) && input.mouseHover(myGroupsButton, window))
	{
		std::cout << "MyGroups clicked" << std::endl; // new myGroupsScreen
	}

	if (input.mouseClick(sf::Mouse::Button::Left) && input.mouseHover(exploreButton, window))
	{
		std::cout << "ExploreButton clicked" << std::endl; // new exploreGroupsScreen
	}
}

void HomeScreen::draw(sf::RenderWindow &window)
{
	window.draw(backgroundSprite);
	window.draw(myGroupsButton);
	window.draw(exploreButton);
}