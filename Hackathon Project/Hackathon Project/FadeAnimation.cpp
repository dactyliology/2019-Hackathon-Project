#include "FadeAnimation.h"

void FadeAnimation::loadContent(std::string newText, sf::Texture newTexture, sf::Vector2f newPosition)
{
	Animation::loadContent(preText, spriteTexture, position);
	increase = false;
	fadeSpeed = FADESPEED;
}

void FadeAnimation::unloadContent()
{

}

void FadeAnimation::update(sf::Time deltaTime)
{
	if (active)
	{
		if (!increase)
			alpha -= deltaTime.asSeconds() * fadeSpeed; // Might need to change
		else
			alpha += deltaTime.asSeconds() * fadeSpeed; // Using time increases the fade speed
		if (alpha >= 1.0f) // opacity >= 255
		{
			alpha = 1.0f; // opacity = 100%
			increase = false; // stop increasing the opacity
		}
		else if (alpha <= 0.0f) // opacity <= 0
		{
			alpha = 0.0f; // opacity = 0%
			increase = true; // start increasing opacity
		}
	}
	else
	{
		alpha = 1.0f;
	}
}

void FadeAnimation::draw(sf::RenderWindow &window)
{
	Animation::draw(window);
}

void FadeAnimation::setAlpha(double val)
{
	alpha = val;
	if (alpha == 0.0)
		increase = true;
	else
		increase = false;
}