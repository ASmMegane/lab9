#include "stdafx.h"
#include "applicationData.h"

AppData::AppData() {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	window.create(sf::VideoMode(800, 600), "lab9", sf::Style::Default, settings);
	font.loadFromFile("arial.ttf");

	checkBox.setPosition(sf::Vector2f(100, 100));
	checkBox.text.setFont(font);
	checkBox.text.setString("Call textBox");
	checkBox.text.setCharacterSize(15);
	checkBox.arrangeElements();
	checkBox.handlerEventPress = [&]() {
		textBox.isVisible = checkBox.isActive;
		};

	textBox.setPosition(sf::Vector2f(400, 100));
	textBox.text.setFont(font);
	textBox.isVisible = false;
	textBox.text.setCharacterSize(15);
	textBox.arrangeElements();
};


void AppData::runApp() {
	while (window.isOpen()) {
		window.clear();
		checkBox.draw(window);
		textBox.draw(window);
		window.display();		
		sf::Event event;
		while (window.waitEvent(event)) {
			if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();
			if (textBox.OnEvent(event))
				break;
			if (checkBox.OnEvent(event))
				break;
		}
	}
}