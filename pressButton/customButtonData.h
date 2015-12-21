#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <functional>


struct CustomButton {

	CustomButton();

	sf::RectangleShape shape;
	sf::Text text;
	bool isVisible;
	enum ColorState {
		normal, hovered, pressed
	};
	ColorState colorState;

	bool intersectWithMouse(int posMouseX, int posMouseY);
	void draw(sf::RenderWindow & window);
	bool OnEvent(sf::Event & event);
	void setPosition(sf::Vector2f const & position);
	void setSize(sf::Vector2f const & size);
	void arrangeElements();
	bool setColorState(ColorState colorState);
	std::function<void()> handlerEventPress;
};
