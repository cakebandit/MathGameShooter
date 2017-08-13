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

	if (!mathShipTexture.loadFromFile("mine.png")) {
		std::cout << "didntload minetexture";
	}

	isAlive = true;

	mathShipSprite.setTexture(mathShipTexture);
	//mathShipSprite.setScale(0.2, 0.2);
	
	int mathEquation1 = (rand() % 10);
	int mathEquation2 = (rand() % 9);

	int answer = mathEquation1 + mathEquation2;

	std::string s = std::to_string(mathEquation1) + " + " + std::to_string(mathEquation2);

	question.setString(s);
	question.setCharacterSize(15);
	question.setFillColor(Color::White);
	question.setStyle(sf::Text::Regular);

	mathShipSprite.setPosition(position);
	question.setPosition(position);
}

Text mathShip::getText() {
	return question;
}

Sprite mathShip::getSprite()
{
	return mathShipSprite;
}

bool mathShip::outOfBounds(Vector2f mathposition) {
	if (mathposition.x < 0) {
		return true;
		std::cout << "hes out";
	}
}

void mathShip::movementMath() {
	position.x = position.x - 0.5;
}

void mathShip::Update() {
	mathShipSprite.setPosition(position);
	question.setPosition(position.x, position.y - 20);
}



