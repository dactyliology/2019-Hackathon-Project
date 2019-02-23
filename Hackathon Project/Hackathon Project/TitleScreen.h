#include "Screen.h"

class TitleScreen : public Screen
{
public:
	void loadContent();
	void unloadContent();
	void update(sf::Event event);
	void draw(sf::RenderWindow & window, sf::Event event);

public:
	// perhaps a single sign in button?
};