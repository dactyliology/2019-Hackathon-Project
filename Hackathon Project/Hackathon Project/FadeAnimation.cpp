#include "FadeAnimation.h"

void FadeAnimation::loadContent()
{
	increase = false;
	fadeSpeed = FADESPEED;

	alpha = 1.0f;
	active = false;
}

void FadeAnimation::unloadContent()
{

}

void FadeAnimation::update(sf::Time deltaTime)
{
	if (active)
	{
		if (!increase)
			alpha -= deltaTime.asSeconds() * fadeSpeed;
		else
			alpha += deltaTime.asSeconds() * fadeSpeed;

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

void FadeAnimation::draw(sf::RenderWindow & window)
{
	window.draw();
}

void FadeAnimation::setAlpha(double val)
{
	alpha = val;
	if (alpha == 0.0)
		increase = true;
	else
		increase = false;
}