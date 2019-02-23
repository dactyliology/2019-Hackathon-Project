#include "Definitions.h"
#include "TitleScreen.h"
#include "FadeAnimation.h"

#define SCREEN_WIDTH 549
#define SCREEN_HEIGHT 976

class ScreenManager
{
public:
	//~ScreenManager();

	// Allows us to access one instance of the screenmanager. We will call this in main.
	static ScreenManager & getInstance();

	// Initialize the ScreenManager instance.
	void initialize();

	// Load the content of current screen
	void loadContent();

	// Unload content of screen
	void unloadContent();

	// Update the screens. Manage the transitions between screens.
	void update(sf::RenderWindow &window, sf::Event event, sf::Time deltaTime);

	// Draw the screen to the window
	void draw(sf::RenderWindow &window);

	// Add a new screen.
	void addScreen(Screen *newScreen);

	float getAlpha();

private:
	Screen *currentScreen, *addedScreen; // should probably be a stack later to faciliate page switching

	// Put constructor, copy constructor, and assignment here so new instances of the object
	// won't "accidentally" be created.
	/*ScreenManager();
	ScreenManager(ScreenManager const &other);
	void operator=(ScreenManager const &other);*/

	void transition(sf::Time deltaTime);

	bool isTransition;

	FadeAnimation fade;
	


};