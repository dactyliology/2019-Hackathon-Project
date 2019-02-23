#include "Screen.h"

class TitleScreen : public Screen
{
public:
	void loadContent();
	void unloadContent();
	void update(sf::RenderWindow &window, sf::Event event);
	void draw(sf::RenderWindow & window);

public:
	// perhaps a single sign in button?
};