#include "SFMLHeader.h"
#include "mathShip.h"
#include "mainship.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

mathShip::mathShip(int startY){
	position.y = startY;
	position.x = 600;

	mathShipPlaceholder.setSize(Vector2f(60, 25));
	
	int mathEquation1 = (rand() % 10);
	int mathEquation2 = (rand() % 9);

	int answer = mathEquation1 + mathEquation2;

	Text question;
	Font font;

	if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
	{
		std::cout << "didnt work";
	}

	//std::string s = std::to_string(mathEquation1) + " + " + std::to_string(mathEquation2);
	std::string s = "meme";

	question.setString(s);
	question.setCharacterSize(20);
	question.setFillColor(Color::White);
	question.setStyle(sf::Text::Regular);

	mathShipPlaceholder.setPosition(position);
	question.setPosition(position);

	mathShip::movementMath();
}

FloatRect mathShip::getPosition()
{
	return mathShipPlaceholder.getGlobalBounds(), question.getGlobalBounds();
}

RectangleShape mathShip::getShape() {
	return mathShipPlaceholder;
}

Text mathShip::getText() {
	std::cout << "william: " , question.getString();
	return question;
	
}

bool mathShip::outOfBounds(Vector2f mathposition) {
	if (mathposition.x < 0) {
		return true;
		std::cout << "hes out";
	}
}

void mathShip::movementMath() {
	position.x = position.x - 1;
}

void mathShip::Update() {
	mathShipPlaceholder.setPosition(position);
	question.setPosition(position);
}



