#include "ScreenManager.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "2019 CrimsonCode App");

	sf::RectangleShape fade(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT)); // black rectangle to facilitate screen fade animation
	fade.setFillColor(sf::Color::White);

	sf::Clock deltaClock;

	ScreenManager::getInstance().initialize();
	ScreenManager::getInstance().loadContent();

	while (window.isOpen())
	{
		sf::Event event;

		deltaClock.restart();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Key::Escape)
				window.close();
		}

		window.clear();

		ScreenManager::getInstance().update(window, event, deltaClock.getElapsedTime());

		fade.setFillColor(sf::Color(0, 0, 0, 255 * ScreenManager::getInstance().getAlpha()));

		ScreenManager::getInstance().draw(window);

		window.display();
	}

	return 0;
}