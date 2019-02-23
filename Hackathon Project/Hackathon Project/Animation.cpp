#include "Animation.h"

void Animation::loadContent(std::string newText, sf::Texture newTexture, sf::Vector2f newPosition)
{
	preText = newText;
	spriteTexture = newTexture;
	position = newPosition;

	alpha = 1.0;
	textColor = sf::Color(114, 77, 255);
	sprite.setTexture(spriteTexture);
	text.setString(preText);

	active = false;
}

void Animation::unloadContent()
{

}

void Animation::update(sf::Time deltaTime)
{

}

void Animation::draw(sf::RenderWindow &window)
{
	std::string str = text.getString();
	if (str != "") // make sure not drawing empty string
		window.draw(text);
	if (sprite.getTexture() != NULL)
		window.draw(sprite);
}

void Animation::setAlpha(double val)
{
	alpha = val;
}

double Animation::getAlpha()
{
	return alpha;
}

void Animation::setActive(bool val)
{
	active = val;
}
