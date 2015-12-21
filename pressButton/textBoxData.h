#pragma once
#include "customButtonData.h"

struct TextBox : CustomButton {
	std::string lineInputValue;
	void arrangeElements();
	bool OnEvent(sf::Event & event);
};
