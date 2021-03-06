#pragma once

#include <iostream>
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include <string>
#include <fstream>
#include <vector>

// Page transition speed

#define FADESPEED 20 
#define FONT "font.ttf"
#define TEXT_COLOR sf::Color::Black

////////////////////// SCREEN IMAGES /////////////////////////

#define TITLESCREEN "TitleScreen.png"
#define HOMESCREEN "HomeScreen.png"
#define MYGROUPS_SCREEN "LongBackground.png"
#define DETAILS_SCREEN "DetailsScreen.png"
#define EXPLOREGROUPS_SCREEN "LongBackground.png"

/////////////////////////////////////////////////////////

#define BUTTON_ORIGINAL_COLOR sf::Color(255, 255, 255)
#define BUTTON_HOVER_COLOR sf::Color(248, 203, 173)

///////////////////////////////// BUTTON IMAGES ////////////////////////////
#define MYGROUPS_BUTTON "myGroupsButton.png"
#define EXPLORE_BUTTON "ExploreButton.png"
#define GROUPS_TILE "GroupsTile.png"
#define HOME_BUTTON "HomeButton.png"
#define BACK_BUTTON "BackButton.png"
#define ADD_BUTTON "AddButton.png"
#define MYGROUPS_HEADER "MyGroupsHeader.png"
#define EXPLOREGROUPS_HEADER "ExploreGroupsHeader.png"
