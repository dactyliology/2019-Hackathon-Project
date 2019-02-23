#include "InputManager.h"

void InputManager::update(sf::Event newEvent)
{
	event = newEvent;
}

bool InputManager::mouseClick(sf::Mouse::Button button)
{
	return sf::Mouse::isButtonPressed(button);
}

bool InputManager::mouseHover(sf::Sprite &object, sf::RenderWindow &window)
{
	sf::Vector2f mouseWorldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	sf::FloatRect globalBounds = object.getGlobalBounds();

	return globalBounds.contains(mouseWorldPos);
}

bool InputManager::mouseScroll(sf::Mouse::Wheel wheel)
{
	return false;
}