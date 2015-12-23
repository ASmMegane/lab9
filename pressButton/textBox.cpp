#include "stdafx.h"
#include "textBoxData.h"

void TextBox::arrangeElements() {
	sf::Vector2f size(300, 150);
	shape.setSize(sf::Vector2f(size));
	text.setColor(sf::Color::Black);
	text.setPosition(shape.getPosition());
}

bool TextBox::OnEvent(sf::Event & event) {
	int backspaceCode = 8;
	int enterCode = 13;
	if (isVisible) {
		if (event.type == sf::Event::TextEntered && colorState == hovered) {
			if (event.text.unicode < 128 && event.text.unicode >= 32) {
				lineInputValue += static_cast<char>(event.text.unicode);
				if ((lineInputValue.size() % ((int)(shape.getSize().x / 12))) == (int)(shape.getSize().x / 12 - 1))
					lineInputValue += "\n";
				text.setString(lineInputValue);
				return true;
			} else if (event.text.unicode < 32) {
				if (event.text.unicode == backspaceCode)
					lineInputValue = lineInputValue.substr(0, lineInputValue.size() - 1);
				text.setString(lineInputValue);
				return true;
			}
		}
		return CustomButton::OnEvent(event);
	}
	return false;
}