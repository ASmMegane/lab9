#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "buttonData.h"

struct AppData {
	AppData();
	sf::RenderWindow window;
	sf::Font font;
	sf::Clock clock;
	CheckBox checkBox;
	TextBox textBox;
	void runApp();	
};
