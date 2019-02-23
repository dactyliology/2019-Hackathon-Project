#include "InputManager.h"

void InputManager::loadContent(sf::Event newEvent)
{
	event = newEvent;
}

bool InputManager::mouseClick(sf::Mouse::Button button)
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}

bool InputManager::mouseHover(sf::Sprite &object, sf::RenderWindow &window)
{

}

bool InputManager::mouseScroll(sf::Mouse::Wheel wheel)
{

}