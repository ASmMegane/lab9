#include "stdafx.h"
#include "customButtonData.h"

CustomButton::CustomButton() {
	shape.setOutlineThickness(5);
	setColorState(normal);
	isVisible = true;
};


bool CustomButton::intersectWithMouse(int posMouseX, int posMouseY) {
	if (posMouseX > shape.getPosition().x && posMouseX < shape.getPosition().x + shape.getSize().x
		&& posMouseY > shape.getPosition().y && posMouseY < shape.getPosition().y + shape.getSize().y) {
		return true;
	}
	return false;
};

void CustomButton::setPosition(sf::Vector2f const & position) {
	shape.setPosition(position);
};

void CustomButton::setSize(sf::Vector2f const & size) {
	shape.setSize(size);
};

void CustomButton::arrangeElements() {
	text.setPosition(shape.getPosition());
	text.setCharacterSize((unsigned int)shape.getSize().x / text.getString().getSize());
}

bool CustomButton::setColorState(ColorState clrState) {
	if (colorState != clrState) {
		colorState = clrState;
		switch (colorState) {
		case CustomButton::normal:
			shape.setOutlineColor(sf::Color::Green);
			break;
		case CustomButton::hovered:
			shape.setOutlineColor(sf::Color::Yellow);
			break;
		case CustomButton::pressed:
			shape.setOutlineColor(sf::Color::Red);
			break;
		}
		return true;
	}
	return false;
};

void CustomButton::draw(sf::RenderWindow & window) {
	if (isVisible) {
		window.draw(shape);
		window.draw(text);
	}
};

bool CustomButton::OnEvent(sf::Event & event) {
	if (isVisible) {
		if (event.type == sf::Event::MouseMoved) {
			if (intersectWithMouse(event.mouseMove.x, event.mouseMove.y))
				return setColorState(hovered);
			else
				return setColorState(normal);
		}
		if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left && intersectWithMouse(event.mouseButton.x, event.mouseButton.y)) {
			setColorState(pressed);
			return true;
		}
		if ((event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left) && intersectWithMouse(event.mouseButton.x, event.mouseButton.y)) {
			setColorState(hovered);
			if (handlerEventPress)
				handlerEventPress();
			return true;
		}
	}
	return false;
}

