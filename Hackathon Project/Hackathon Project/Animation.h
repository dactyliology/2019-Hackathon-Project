#pragma once

#include "Definitions.h"

// Base class for animations
class Animation
{
public:
	virtual void loadContent(std::string newText, sf::Texture newTexture, sf::Vector2f newPosition);
	virtual void unloadContent();
	virtual void update(sf::Time deltaTime);
	virtual void draw(sf::RenderWindow &window);

	virtual void setAlpha(double val);
	double getAlpha();

	void setActive(bool value);
protected:
	double alpha;
	std::string preText;
	sf::Text text;
	sf::Texture spriteTexture;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Color textColor;

	sf::IntRect sourceRect; // is this needed?
	bool active;
private:
};