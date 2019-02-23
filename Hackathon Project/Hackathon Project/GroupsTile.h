#pragma once

#include "Definitions.h"

// This class is for a group tile, used on the myGroupsScreen and exploreGroups screens

class GroupsTile : public sf::Sprite
{
public:
	void loadContent(); 

	// Calculates where the groupTile should go based on its pos in a 1D array
	void setPositionFromArrayIndex(int index, int gap, int offset);

	// Data members
	std::string department;
	std::string classNumber;
	std::string classAbbreviation;
	std::string contactLink;
	std::string rating;

private:
	sf::Texture tileTexture;
};

std::fstream & operator >> (std::fstream &lhs, GroupsTile &rhs);
std::fstream & operator << (std::fstream &lhs, GroupsTile &rhs);