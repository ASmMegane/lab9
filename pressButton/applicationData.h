#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include "checkBoxData.h"
#include "textBoxData.h"

struct AppData {
	AppData();
	sf::RenderWindow window;
	sf::Font font;
	sf::Clock clock;
	CheckBox checkBox;
	TextBox textBox;
	void runApp();	
};
