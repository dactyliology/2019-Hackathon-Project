#pragma once

#include "Animation.h"

class FadeAnimation : public Animation
{
public:
	void loadContent(std::string newText, sf::Texture newTexture, sf::Vector2f newPosition);
	void unloadContent();
	void update(sf::Time deltaTime);
	void draw(sf::RenderWindow & window);

	void setAlpha(double val);

private:
	bool increase;
	double fadeSpeed;

};