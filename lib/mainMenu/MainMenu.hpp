#include "Platform/Platform.hpp"
#define maxMainMenu 3

class MainMenu
{
public:
	MainMenu(float width, float height);

	void Draw(RenderWindow& window);
	void moveUp();
	void moveDown();

	int mainMenuPressed()
	{
		return mainMenuSelected;
	}
	~MainMenu();

private:
	int mainMenuSelected;
	sf::Font font;
	sf::Text mainMenu[maxMainMenu];
};