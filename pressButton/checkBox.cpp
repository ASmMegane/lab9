#include "stdafx.h"
#include "checkBoxData.h"

void CheckBox::draw(sf::RenderWindow & window) {
	if (isVisible) {
		CustomButton::draw(window);
		if (isActive)
			window.draw(checkMark);
	}
}

void CheckBox::arrangeElements() {
	shape.setSize(sf::Vector2f((float)(text.getString().getSize() * text.getCharacterSize() / 2), (float)text.getCharacterSize() * 4));
	text.setPosition(shape.getPosition());
	text.setColor(sf::Color::Black);
	checkMark.setRadius((float)text.getCharacterSize());
	checkMark.setFillColor(sf::Color::Green);
	checkMark.setPosition(shape.getPosition().x + shape.getSize().x / 2 - checkMark.getRadius(), shape.getPosition().y + shape.getSize().y - checkMark.getRadius() * 2.5f);
}
