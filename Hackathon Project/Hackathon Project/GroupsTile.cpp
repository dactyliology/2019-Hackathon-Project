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
}

void GroupsTile::setPositionFromArrayIndex(int index, int gap, int offset)
{
	float x = (index % 2) * (gap + this->getGlobalBounds().width) + gap;
	float y = (index / 2) * (gap + this->getGlobalBounds().height) + offset;

	this->setPosition(x, y);
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
		<< rhs.rating << std::endl;	

	return lhs;
}