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
	/*sf::Vector2f mouseWorldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	sf::FloatRect globalBounds = object.getGlobalBounds();

	return globalBounds.contains(mouseWorldPos);*/

	if (sf::Mouse::getPosition(window).x > object.getPosition().x
		&& sf::Mouse::getPosition(window).x < object.getPosition().x + object.getGlobalBounds().width
		&& sf::Mouse::getPosition(window).y > object.getPosition().y
		&& sf::Mouse::getPosition(window).y < object.getPosition().y + object.getGlobalBounds().height)

		return true;
	return false;
}

bool InputManager::mouseScroll(sf::Mouse::Wheel wheel)
{
	return false;
}