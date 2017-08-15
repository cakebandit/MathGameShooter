#include "SFMLHeader.h"
#include "mathShip.h"
#include "mainship.h"
#include <iostream>
#include <string>
#include <time.h>
#include <sstream>
#include <random>
#include <cstdlib>

mathShip::mathShip(int startY){
	position.y = startY;
	position.x = 600;

	srand(time(NULL));

	if (!mathShipTexture.loadFromFile("mine.png")) {
		std::cout << "didntload minetexture";
	}
	isAlive = true;

	mathShipSprite.setTexture(mathShipTexture);

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

int mathShip::answerquestion(int mathShipQuestion) {
	std::cout << mathEquation1;
	if (answer == mathShipQuestion) {
		
		return isAlive = false;
	}
	else
		return isAlive = true;
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



