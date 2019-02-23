#include "Button.h"

void Button::loadContent(std::string filename)
{
	if (buttonImage.loadFromFile(filename))
	{
		buttonImage.setSmooth(true);
		this->setTexture(buttonImage);
	}
	else
		std::cout << "Could not load button image" << std::endl;
}
