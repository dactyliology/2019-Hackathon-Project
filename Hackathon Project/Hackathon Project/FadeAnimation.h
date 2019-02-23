#include "Definitions.h"

class FadeAnimation
{
public:
	void loadContent();
	void unloadContent();
	void update(sf::Time deltaTime);
	void draw(sf::RenderWindow & window);

	void setAlpha(double val);

private:
	bool increase;
	double fadeSpeed;

	bool active;
	double alpha; // opacity value
};