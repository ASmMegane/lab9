#pragma once
#include "customButtonData.h"

struct CheckBox : CustomButton {
	CheckBox() : CustomButton() {
		isActive = false;
	};
	sf::CircleShape checkMark;
	bool isActive;
	void arrangeElements();
	void draw(sf::RenderWindow & window);
};