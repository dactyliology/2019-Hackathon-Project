#include "GroupsTile.h"

void GroupsTile::loadContent()
{
	if (tileTexture.loadFromFile(GROUPS_TILE))
	{
		tileTexture.setSmooth(true);
		this->setTexture(tileTexture);
	}
	else
		std::cout << "Could not load Groups Tile image" << std::endl;

	if (font.loadFromFile(FONT))
		tileText.setFont(font);
	tileText.setColor(TEXT_COLOR);
	tileText.setCharacterSize(50);
	tileText.setStyle(sf::Text::Style::Bold);
	tileText.setString("  " + this->classAbbreviation + '\n' + "   " + this->classNumber);
}

void GroupsTile::setPositionFromArrayIndex(int index, int gap, int offset)
{
	float x = (index % 2) * (gap + this->getGlobalBounds().width) + gap;
	float y = (index / 2) * (gap + this->getGlobalBounds().height) + offset;

	this->setPosition(x, y);
}

void GroupsTile::operator=(GroupsTile &rhs)
{
	this->department = rhs.department;
	this->classNumber = rhs.classNumber;
	this->classAbbreviation = rhs.classAbbreviation;
	this->contactLink = rhs.contactLink;
	this->rating = rhs.rating;
}

std::fstream & operator >> (std::fstream &lhs, GroupsTile &rhs)
{
	std::getline(lhs, rhs.department, ',');
	std::getline(lhs, rhs.classNumber, ',');
	std::getline(lhs, rhs.classAbbreviation, ',');
	std::getline(lhs, rhs.contactLink, ',');
	std::getline(lhs, rhs.rating, '\n');
	
	return lhs;
}

std::fstream & operator << (std::fstream &lhs, GroupsTile &rhs)
{
	lhs << rhs.department << ','
		<< rhs.classNumber << ','
		<< rhs.classAbbreviation << ','
		<< rhs.contactLink << ','
		<< rhs.rating;

	return lhs;
}